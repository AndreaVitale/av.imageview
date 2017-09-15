/**
 * This module was developed by
 * Andrea Vitale
 * vitale.andrea@me.com
 *
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2016 by Appcelerator, Inc. All Rights Reserved.
 */

#import "TiUIView.h"
#import "SDWebImage/UIImageView+WebCache.h"
#import "SDWebImage/FLAnimatedImage/FLAnimatedImageView+WebCache.h"

@interface AvImageviewImageView : TiUIView {
    @private
        BOOL loadingIndicator;
        BOOL clipsToBounds;

        TiDimension width;
        TiDimension height;
        CGFloat autoHeight;
        CGFloat autoWidth;
    
        FLAnimatedImageView *imageView;
        UIViewContentMode contentMode;
        UIActivityIndicatorView  *activityIndicator;

        NSString *placeholderImagePath;
        NSString *brokenLinkImagePath;
    
        NSDictionary *requestHeader;
        SDWebImageOptions handleCookies;
}

-(void)setWidth_:(id)width;
-(void)setHeight_:(id)height;
-(void)setImage_:(id)args;
-(void)setDefaultImage_:(id)args;
-(void)setBrokenLinkImage_:(id)args;
-(void)setLoadingIndicator_:(id)args;
-(void)setContentMode_:(id)args;
-(void)setClipsToBounds_:(id)clips;
-(void)setRequestHeader_:(id)args;

@end
