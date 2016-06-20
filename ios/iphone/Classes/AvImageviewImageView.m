/**
 * This module was developed by
 * Andrea Vitale
 * vitale.andrea@me.com
 *
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2016 by Appcelerator, Inc. All Rights Reserved.
 */

#import "AvImageviewImageView.h"

@implementation AvImageviewImageView

-(void)initializeState {
    [super initializeState];
    
    if (self) {
        [self processProperties];
        
        imageView = [[UIImageView alloc] initWithFrame:[self frame]];
        imageView.contentMode = UIViewContentModeScaleAspectFill;
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
    [self setLoadingIndicator_:[[self.proxy allProperties] valueForKey:@"loadingIndicator"]];
}

-(void)frameSizeChanged:(CGRect)frame bounds:(CGRect)bounds {
    for (UIView *child in [self subviews])
        [TiUtils setView:child positionRect:bounds];
    
    [super frameSizeChanged:frame bounds:bounds];
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

-(void)setImage_:(id)args {
    ENSURE_TYPE(args, NSString);
    
    UIImage *placeholderImage = (placeholderImagePath != nil) ? [self loadLocalImage:placeholderImagePath] : nil;
    UIImage *brokenLinkImage = (brokenLinkImagePath != nil) ? [self loadLocalImage:brokenLinkImagePath] : nil;
    
    NSURL *imageUrl = [NSURL URLWithString:[TiUtils stringValue:args]];
    
    if (loadingIndicator)
        [activityIndicator startAnimating];
    
    if ([imageUrl.scheme isEqualToString:@"http"] || [imageUrl.scheme isEqualToString:@"https"]) {
        [imageView cancelCurrentImageLoad];
        [imageView setImageWithURL:imageUrl
                  placeholderImage:placeholderImage
                         completed:^(UIImage *image, NSError *error, SDImageCacheType cacheType) {
                             NSDictionary *event = [NSDictionary dictionaryWithObject:[imageUrl absoluteString] forKey:@"image"];
                             
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
                             
                             [self fadeImage:cacheType];
                         }
         ];
    } else {
        imageView.image = [self loadLocalImage:[TiUtils stringValue:args]];
        
        if (loadingIndicator)
            [activityIndicator stopAnimating];
    }
}
    
-(void)setDefaultImage_:(id)args {
    placeholderImagePath = [TiUtils stringValue:args];
}
    
-(void)setBrokenLinkImage_:(id)args {
    brokenLinkImagePath = [TiUtils stringValue:args];
}

-(void)setContentMode_:(id)args {
    ENSURE_TYPE(args, NSNumber);
    
    [imageView setContentMode:[TiUtils intValue:args def:UIViewContentModeScaleAspectFit]];
}

-(void)setClipsToBounds_:(id)clips {
    clipsToBounds = [TiUtils boolValue:clips def:NO];
    imageView.clipsToBounds = clipsToBounds;
}

-(void)setLoadingIndicator_:(id)value {
    loadingIndicator = [TiUtils boolValue:value def:YES];
}

@end
