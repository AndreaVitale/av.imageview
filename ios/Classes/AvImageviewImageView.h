/**
 * This module was developed by
 * Andrea Vitale
 * vitale.andrea@me.com
 *
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2016 by Appcelerator, Inc. All Rights Reserved.
 */

#import <SDWebImage/SDWebImage.h>
#import "TiUIView.h"

@interface AvImageviewImageView : TiUIView {
  @private
  BOOL loadingIndicator;
  BOOL clipsToBounds;
  TiColor *loadingIndicatorColor;

  TiDimension width;
  TiDimension height;
  CGFloat autoHeight;
  CGFloat autoWidth;

  SDAnimatedImageView *imageView;
  UIActivityIndicatorView *activityIndicator;

  NSString *placeholderImagePath;
  NSString *brokenLinkImagePath;

  NSDictionary *requestHeaders;
  id imageObject;
  BOOL configurationComplete;

  // Options
  BOOL useCookies;
  BOOL avoidDecodeImage;
}

- (void)setWidth_:(id)width;
- (void)setHeight_:(id)height;
- (void)setImage_:(id)args;
- (void)setDefaultImage_:(id)args;
- (void)setBrokenLinkImage_:(id)args;
- (void)setLoadingIndicator_:(id)args;
- (void)setLoadingIndicatorColor_:(id)args;
- (void)setContentMode_:(id)args;
- (void)setClipsToBounds_:(id)clips;
- (void)setRequestHeaders_:(id)args;
- (void)setTimeout_:(id)args;

@end
