/**
 * This module was developed by
 * Andrea Vitale
 * vitale.andrea@me.com
 *
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2016 by Appcelerator, Inc. All Rights Reserved.
 */

#import "AvImageviewImageView.h"
#import "AvImageviewImageViewProxy.h"
#import "TiApp.h"
#import "TiBase.h"
#import "TiBlob.h"
#import "TiProxy.h"
#import "TiUtils.h"
#import "TiViewProxy.h"
#import <CommonCrypto/CommonDigest.h>

@interface AvImageviewImageView ()

@end
@implementation AvImageviewImageView

- (void)initializeState {
  [super initializeState];

  if (self) {
    imageView = [[SDAnimatedImageView alloc] initWithFrame:[self bounds]];
    imageView.clipsToBounds = YES;

    activityIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
    activityIndicator.center = CGPointMake(self.frame.size.width / 2, self.frame.size.height / 2);
    activityIndicator.hidesWhenStopped = YES;
    activityIndicator.hidden = YES;

    [self addSubview:imageView];
    [self addSubview:activityIndicator];
  }
}
- (void)configurationSet {
  // This method is called right after all view properties have
  // been initialized from the view proxy. If the view is dependent
  // upon any properties being initialized then this is the method
  // to implement the dependent functionality.
  [super configurationSet];
  configurationComplete = YES;
  [self displayImage:imageObject];
}
//this looks like redundant code, prob a leftover
- (void)processProperties {
  [self setImage_:[self.proxy valueForKey:@"image"]];
  [self setDefaultImage_:[self.proxy valueForKey:@"defaultImage"]];
  [self setBrokenLinkImage_:[self.proxy valueForKey:@"brokenLinkImage"]];
  [self setLoadingIndicator_:[self.proxy valueForKey:@"loadingIndicator"]];
  [self setLoadingIndicatorColor_:[self.proxy valueForKey:@"loadingIndicatorColor"]];
  [self setContentMode_:[self.proxy valueForKey:@"contentMode"]];
  [self setRequestHeaders_:[self.proxy valueForKey:@"requestHeaders"]];
  [self setHandleCookies_:[self.proxy valueForKey:@"handleCookies"]];
}

- (void)frameSizeChanged:(CGRect)frame bounds:(CGRect)bounds {
  for (UIView *child in [self subviews])
    [TiUtils setView:child positionRect:bounds];

  [super frameSizeChanged:frame bounds:bounds];
  [self updateContentMode];
}

- (UIImage *)loadImageFromAssetsCatalog:(NSURL *)img {
  UIImage *image = nil;

  NSString *imageArg = nil;
  NSString *pathStr = [img path];

  NSRange range = [pathStr rangeOfString:@".app"];

  if (range.location != NSNotFound)
    imageArg = [pathStr substringFromIndex:range.location + 5];

  imageArg = [imageArg stringByReplacingOccurrencesOfString:@"@3x" withString:@""];
  imageArg = [imageArg stringByReplacingOccurrencesOfString:@"@2x" withString:@""];
  imageArg = [imageArg stringByReplacingOccurrencesOfString:@"~iphone" withString:@""];
  imageArg = [imageArg stringByReplacingOccurrencesOfString:@"~ipad" withString:@""];

  if (imageArg != nil) {
    // Handle asset catalog in SDK 9+
    image = [UIImage imageNamed:imageArg];

    // Handle asset catalog in SDK < 9
    if (image == nil) {
      unsigned char digest[CC_SHA1_DIGEST_LENGTH];
      NSData *stringBytes = [imageArg dataUsingEncoding:NSUTF8StringEncoding];

      if (CC_SHA1([stringBytes bytes], (CC_LONG)[stringBytes length], digest)) {
        NSMutableString *sha = [[NSMutableString alloc] init];

        for (int i = 0; i < CC_SHA1_DIGEST_LENGTH; i++)
          [sha appendFormat:@"%02x", digest[i]];

        [sha appendString:@"."];
        [sha appendString:[img pathExtension]];

        image = [UIImage imageNamed:sha];
      }
    }
  }

  if (image == nil)
    image = [UIImage imageWithContentsOfFile:[img path]];

  return image;
}

- (void)displayImage:(id)imageObj {
  UIImage *placeholderImage = (placeholderImagePath != nil) ? [self loadLocalImage:placeholderImagePath] : nil;
  UIImage *brokenLinkImage = (brokenLinkImagePath != nil) ? [self loadLocalImage:brokenLinkImagePath] : nil;

  if ([imageObj isKindOfClass:[NSNull class]]) {
    [imageView setImage:nil];

    return;
  }

  [SDWebImagePrefetcher.sharedImagePrefetcher cancelPrefetching];

  if ([imageObj isKindOfClass:[NSString class]]) {
    //fix downloading the image if url contains spaces or none ASCII characters
    //source : https://stackoverflow.com/questions/1441106/nsdata-nsurl-url-with-space-having-problem
    NSString *srtImageUrl = [TiUtils stringValue:imageObj];
    srtImageUrl = [srtImageUrl stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];

    NSURL *imageUrl = [NSURL URLWithString:srtImageUrl];

    if (loadingIndicator) {
      activityIndicator.hidden = NO;

      if (loadingIndicatorColor != nil) {
        activityIndicator.color = [loadingIndicatorColor color];
      }

      [activityIndicator startAnimating];
    }
    
    // Set options
    SDWebImageOptions imageOptions = [self configureImageOptions];

    if ([imageUrl.scheme isEqualToString:@"http"] || [imageUrl.scheme isEqualToString:@"https"]) {
      NSString *userAgent = [[TiApp app] userAgent];

      [[SDWebImageDownloader sharedDownloader] setValue:userAgent forHTTPHeaderField:@"User-Agent"];

      //Extending HTTP header with custom values
      if (requestHeaders != nil)
        for (id key in requestHeaders)
          [[SDWebImageDownloader sharedDownloader] setValue:[requestHeaders valueForKey:key] forHTTPHeaderField:key];

      [imageView sd_setImageWithURL:imageUrl
                   placeholderImage:placeholderImage
                            options:imageOptions
                          completed:^(UIImage *image, NSError *error, SDImageCacheType cacheType, NSURL *url) {
                            self->autoWidth = image.size.width;
                            self->autoHeight = image.size.height;

                            NSMutableDictionary *event = [[NSMutableDictionary alloc] init];

                            [event setValue:[imageUrl absoluteString] forKey:@"image"];
                            [event setValue:[[NSNumber alloc] initWithFloat:image.size.width] forKey:@"width"];
                            [event setValue:[[NSNumber alloc] initWithFloat:image.size.height] forKey:@"height"];

                            if (error != nil) {
                              if (brokenLinkImage != nil)
                                self->imageView.image = brokenLinkImage;

                              [event setValue:[error localizedDescription] forKey:@"reason"];

                              if ([self.proxy _hasListeners:@"error"])
                                [self.proxy fireEvent:@"error" withObject:event];
                            } else {
                              if ([self.proxy _hasListeners:@"load"])
                                [self.proxy fireEvent:@"load" withObject:event];
                            }

                            if ([self->activityIndicator isAnimating])
                              [self->activityIndicator stopAnimating];

                            [(TiViewProxy *)[self proxy] contentsWillChange];

                            [self fadeImage:cacheType];
                          }];
    } else {
      if ([TiUtils stringValue:imageObj].length > 0)
        imageView.image = [self loadLocalImage:[TiUtils stringValue:imageObj]];

      if (loadingIndicator)
        [activityIndicator stopAnimating];
    }
  } else if ([imageObj isKindOfClass:[TiBlob class]]) {
    TiBlob *blob = (TiBlob *)imageObj;

    imageView.image = [blob image];
  }
}

- (UIImage *)loadLocalImage:(NSString *)imagePath {
  if (imagePath == nil || imagePath.length == 0) {
    return nil;
  }

  if (imagePath != nil) {
    UIImage *image = nil;

    //Load image from asset
    image = [self loadImageFromAssetsCatalog:[TiUtils toURL:imagePath proxy:self.proxy]];

    if (image != nil)
      return image;

    // Load the image from the application assets
    NSString *fileNamePath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:imagePath];
    image = [UIImage imageWithContentsOfFile:fileNamePath];

    if (image != nil)
      return image;

    //image from URL
    image = [UIImage imageWithData:[NSData dataWithContentsOfURL:[NSURL URLWithString:imagePath]]];

    if (image != nil)
      return image;

    //load remote image
    image = [UIImage imageWithContentsOfFile:imagePath];

    if (image != nil)
      return image;

    //Load local image by extracting the filename without extension
    NSString *newImagePath = [[imagePath lastPathComponent] stringByDeletingPathExtension];
    image = [UIImage imageNamed:newImagePath];

    if (image != nil)
      return image;
  }

  return nil;
}

- (void)fadeImage:(SDImageCacheType)cacheType {
  if (cacheType == SDImageCacheTypeNone) {
    imageView.alpha = 0.0;

    [UIView animateWithDuration:0.3
                     animations:^{
                       self->imageView.alpha = 1.0;
                     }];
  } else {
    imageView.alpha = 1.0;
  }
}

- (SDWebImageOptions)configureImageOptions
{
  SDWebImageOptions imageOptions = 0;

  if (useCookies) {
    imageOptions |= SDWebImageHandleCookies;
  }

  if (avoidDecodeImage) {
    imageOptions |= SDImageCacheAvoidDecodeImage;
  }

  return imageOptions;
}

#pragma mark Public setter methods

- (void)setWidth_:(id)width_ {
  width = TiDimensionFromObject(width_);
  [self updateContentMode];
}

- (void)setHeight_:(id)height_ {
  height = TiDimensionFromObject(height_);
  [self updateContentMode];
}

- (void)setImage_:(id)args {
  imageObject = args;
  if (configurationComplete) {
    [self displayImage:imageObject];
  }
}

- (void)setDefaultImage_:(id)args {
  placeholderImagePath = [TiUtils stringValue:args];

  if (placeholderImagePath != nil) {
    imageView.image = (placeholderImagePath != nil) ? [self loadLocalImage:placeholderImagePath] : nil;
    [self fadeImage:SDImageCacheTypeDisk];
  }
}

- (void)setBrokenLinkImage_:(id)args {
  brokenLinkImagePath = [TiUtils stringValue:args];
}

- (void)setContentMode_:(id)args {
  [imageView setContentMode:[TiUtils intValue:args def:UIViewContentModeScaleAspectFill]];
}

- (void)setClipsToBounds_:(id)clips {
  clipsToBounds = [TiUtils boolValue:clips def:NO];
  imageView.clipsToBounds = clipsToBounds;
}

- (void)setLoadingIndicator_:(id)value {
  loadingIndicator = [TiUtils boolValue:value def:YES];
}

- (void)setLoadingIndicatorColor_:(id)value {
  loadingIndicatorColor = [TiUtils colorValue:value];
}

- (void)setRequestHeaders_:(id)args {
  requestHeaders = args;
}

- (void)setHandleCookies_:(id)args {
  useCookies = [TiUtils boolValue:args];
}

- (void)setAvoidDecodeImage_:(id)args {
  avoidDecodeImage = [TiUtils boolValue:args];
}

- (void)setTimeout_:(id)args {
  NSTimeInterval timeout = [TiUtils doubleValue:args def:5000] / 1000;
  SDWebImageDownloaderConfig.defaultDownloaderConfig.downloadTimeout = timeout;
}

#pragma mark utility methodds
- (CGFloat)contentWidthForWidth:(CGFloat)suggestedWidth {
  if (autoWidth > 0) {
    //If height is DIP returned a scaled autowidth to maintain aspect ratio
    if (TiDimensionIsDip(height) && autoHeight > 0) {
      return roundf(autoWidth * height.value / autoHeight);
    }

    return autoWidth;
  }

  CGFloat calculatedWidth = TiDimensionCalculateValue(width, autoWidth);

  if (calculatedWidth > 0) {
    return calculatedWidth;
  }

  return 0;
}

- (CGFloat)contentHeightForWidth:(CGFloat)width_ {
  if (width_ != autoWidth && autoWidth > 0 && autoHeight > 0) {
    return (width_ * autoHeight / autoWidth);
  }

  if (autoHeight > 0)  {
    return autoHeight;
  }

  CGFloat calculatedHeight = TiDimensionCalculateValue(height, autoHeight);

  if (calculatedHeight > 0) {
    return calculatedHeight;
  }

  return 0;
}

- (void)updateContentMode {
  if (imageView != nil) {
    [imageView setContentMode:[self contentModeForImageView]];
  }
}

- (UIViewContentMode)contentModeForImageView {
  if ([[self.proxy allProperties] valueForKey:@"contentMode"] != nil) {
    return [TiUtils intValue:[[self.proxy allProperties] valueForKey:@"contentMode"] def:UIViewContentModeScaleAspectFit];
  } else if (TiDimensionIsAuto(width) || TiDimensionIsAutoSize(width) || TiDimensionIsUndefined(width) || TiDimensionIsAuto(height) || TiDimensionIsAutoSize(height) || TiDimensionIsUndefined(height)) {
    return UIViewContentModeScaleAspectFit;
  } else {
    return UIViewContentModeScaleToFill;
  }
}

@end
