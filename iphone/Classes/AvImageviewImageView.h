/**
 * This module was developed by
 * Andrea Vitale
 * vitale.andrea@me.com
 *
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2016 by Appcelerator, Inc. All Rights Reserved.
 */

#import "TiUIView.h"
#import <SDWebImage/UIImageView+WebCache.h>

@interface AvImageviewImageView : TiUIView {
    @private
        bool clipsToBounds;
        UIViewContentMode contentMode;
        UIImageView *imageView;
        UIActivityIndicatorView  *activityIndicator;
    
        NSString *placeholderImagePath;
        NSString *brokenLinkImagePath;
}

-(void)setImage_:(id)args;
-(void)setContentMode_:(id)args;
-(void)setClipsToBounds_:(id)clips;

-(void)startActivityIndicator;
-(void)stopActivityIndicator;

@end
