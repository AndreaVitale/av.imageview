/**
 * This module was developed by
 * Andrea Vitale
 * vitale.andrea@me.com
 *
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2016 by Appcelerator, Inc. All Rights Reserved.
 */

#import "TiBase.h"
#import "TiUtils.h"
#import "TiViewProxy.h"
#import "TiProxy.h"
#import "TiBlob.h"
#import "AvImageviewImageViewProxy.h"
#import "AvImageviewImageView.h"

@implementation AvImageviewImageView

-(void)initializeState {
    [super initializeState];

    if (self) {
        [self processProperties];

        imageView = [[UIImageView alloc] initWithFrame:[self bounds]];
        //imageView.autoresizingMask = UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
        imageView.clipsToBounds = YES;

        [self addSubview:imageView];

        if (loadingIndicator) {
            activityIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
            activityIndicator.center = CGPointMake(self.frame.size.width/2, self.frame.size.height/2);
            activityIndicator.hidesWhenStopped = YES;
            activityIndicator.hidden = NO;

            [self addSubview:activityIndicator];
        }
    }
}

-(void)processProperties {
    [self setDefaultImage_: [[self.proxy allProperties] valueForKey:@"defaultImage"]];
    [self setBrokenLinkImage_: [[self.proxy allProperties] valueForKey:@"brokenLinkImage"]];
    [self setLoadingIndicator_: [[self.proxy allProperties] valueForKey:@"loadingIndicator"]];
    [self setContentMode_: [[self.proxy allProperties] valueForKey:@"contentMode"]];
}

-(void)frameSizeChanged:(CGRect)frame bounds:(CGRect)bounds {
    for (UIView *child in [self subviews])
        [TiUtils setView:child positionRect:bounds];

    [super frameSizeChanged:frame bounds:bounds];
    [self updateContentMode];
}

-(void)dealloc {
    RELEASE_TO_NIL(imageView);
    RELEASE_TO_NIL(activityIndicator);

    [super dealloc];
}

-(UIImage *)loadLocalImage:(NSString *)imagePath {
    if(imagePath != nil){
        UIImage *image = nil;

        //image from URL
        image = [UIImage imageWithData:[NSData dataWithContentsOfURL:[NSURL URLWithString:imagePath]]];

        if (image != nil)
            return image;

        //load remote image
        image = [UIImage imageWithContentsOfFile:imagePath];

        if (image != nil)
            return image;

        // Load the image from the application assets
        NSString *fileNamePath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:imagePath];;
        image = [UIImage imageWithContentsOfFile:fileNamePath];

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

-(void)fadeImage:(SDImageCacheType) cacheType {
    if (cacheType == SDImageCacheTypeNone) {
        imageView.alpha = 0;

        [UIView animateWithDuration:0.3 animations:^{
            imageView.alpha = 1;
        }];
    } else
        imageView.alpha = 1;
}

#pragma mark Public setter methods

-(void)setWidth_:(id)width_ {
    width = TiDimensionFromObject(width_);
    [self updateContentMode];
}

-(void)setHeight_:(id)height_ {
    height = TiDimensionFromObject(height_);
    [self updateContentMode];
}

-(void)setImage_:(id)args {
    UIImage *placeholderImage = (placeholderImagePath != nil) ? [self loadLocalImage:placeholderImagePath] : nil;
    UIImage *brokenLinkImage = (brokenLinkImagePath != nil) ? [self loadLocalImage:brokenLinkImagePath] : nil;

    if ([args isKindOfClass:[NSNull class]])
        return;
    else if ([args isKindOfClass:[NSString class]]) {
        NSURL *imageUrl = [NSURL URLWithString:[TiUtils stringValue:args]];

        if (loadingIndicator)
            [activityIndicator startAnimating];

        if ([imageUrl.scheme isEqualToString:@"http"] || [imageUrl.scheme isEqualToString:@"https"]) {
            [imageView cancelCurrentImageLoad];
            [imageView setImageWithURL:imageUrl
                      placeholderImage:placeholderImage
                             completed:^(UIImage *image, NSError *error, SDImageCacheType cacheType) {
                                 autoWidth = image.size.width;
                                 autoHeight = image.size.height;

                                 NSMutableDictionary *event = [[NSMutableDictionary alloc] init];

                                 [event setValue:[imageUrl absoluteString] forKey:@"image"];
                                 [event setValue:[[NSNumber alloc] initWithFloat:image.size.width]  forKey:@"width"];
                                 [event setValue:[[NSNumber alloc] initWithFloat:image.size.height] forKey:@"height"];

                                 if (error != nil && brokenLinkImage != nil) {
                                     imageView.image = brokenLinkImage;

                                     if ([self.proxy _hasListeners:@"error"])
                                        [self.proxy fireEvent:@"error" withObject:event];
                                 } else {
                                     if ([self.proxy _hasListeners:@"load"])
                                         [self.proxy fireEvent:@"load" withObject:event];
                                 }

                                 if (loadingIndicator)
                                    [activityIndicator stopAnimating];

                                 [(TiViewProxy*)[self proxy] contentsWillChange];

                                 [self fadeImage:cacheType];
                             }
             ];
        } else {
            imageView.image = [self loadLocalImage:[TiUtils stringValue:args]];

            if (loadingIndicator)
                [activityIndicator stopAnimating];
        }
    } else if ([args isKindOfClass:[TiBlob class]]) {
        TiBlob *blob = (TiBlob*)args;
        
        imageView.image = [blob image];
    }
}

-(void)setDefaultImage_:(id)args {
    placeholderImagePath = [TiUtils stringValue:args];
}

-(void)setBrokenLinkImage_:(id)args {
    brokenLinkImagePath = [TiUtils stringValue:args];
}

-(void)setContentMode_:(id)args {
    [imageView setContentMode:[TiUtils intValue:args def:UIViewContentModeScaleAspectFill]];
}

-(void)setClipsToBounds_:(id)clips {
    clipsToBounds = [TiUtils boolValue:clips def:NO];
    imageView.clipsToBounds = clipsToBounds;
}

-(void)setLoadingIndicator_:(id)value {
    loadingIndicator = [TiUtils boolValue:value def:YES];
}

#pragma mark utility methodds
-(CGFloat)contentWidthForWidth:(CGFloat)suggestedWidth
{
    if (autoWidth > 0) {
        //If height is DIP returned a scaled autowidth to maintain aspect ratio
        if (TiDimensionIsDip(height) && autoHeight > 0) {
            return roundf(autoWidth*height.value/autoHeight);
        }
        return autoWidth;
    }

    CGFloat calculatedWidth = TiDimensionCalculateValue(width, autoWidth);
    if (calculatedWidth > 0) {
        return calculatedWidth;
    }

    return 0;
}

-(CGFloat)contentHeightForWidth:(CGFloat)width_
{
    if (width_ != autoWidth && autoWidth>0 && autoHeight > 0) {
        return (width_*autoHeight/autoWidth);
    }

    if (autoHeight > 0) {
        return autoHeight;
    }

    CGFloat calculatedHeight = TiDimensionCalculateValue(height, autoHeight);
    if (calculatedHeight > 0) {
        return calculatedHeight;
    }

    return 0;
}

-(void)updateContentMode {
    if (imageView != nil)
        [imageView setContentMode:[self contentModeForImageView]];
}

-(UIViewContentMode)contentModeForImageView {
    if ([[self.proxy allProperties] valueForKey:@"contentMode"] != nil)
        return [TiUtils intValue:[[self.proxy allProperties] valueForKey:@"contentMode"] def:UIViewContentModeScaleAspectFit];
    else if (TiDimensionIsAuto(width) || TiDimensionIsAutoSize(width) || TiDimensionIsUndefined(width) ||
        TiDimensionIsAuto(height) || TiDimensionIsAutoSize(height) || TiDimensionIsUndefined(height)) {

        return UIViewContentModeScaleAspectFit;
    } else
        return UIViewContentModeScaleToFill;
}

@end
