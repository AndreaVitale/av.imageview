/**
 * This module was developed by
 * Andrea Vitale
 * vitale.andrea@me.com
 *
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2016 by Appcelerator, Inc. All Rights Reserved.
 */

#import "AvImageviewModule.h"
#import <SDWebImage/SDWebImage.h>
#import "TiBase.h"
#import "TiHost.h"
#import "TiUtils.h"

@implementation AvImageviewModule

#pragma mark Internal

- (id)moduleGUID {
  return @"ddffa9fa-4366-40f0-9031-d32000a82138";
}

- (NSString *)moduleId {
  return @"av.imageview";
}

#pragma Public APIs

- (void)setShouldCacheImagesInMemory:(id)shouldCacheImagesInMemory {
  ENSURE_SINGLE_ARG(shouldCacheImagesInMemory, NSNumber);
  [SDImageCache sharedImageCache].config.shouldCacheImagesInMemory = [TiUtils boolValue:shouldCacheImagesInMemory];
}

- (void)setShouldDecompressImages:(id)shouldDecompressImages {
  NSLog(@"[ERROR] The \"shouldDecompressImages\" property was removed in AV.ImageView iOS 2.0.0 in favor of the per-image option \"avoidDecodeImage\"!");
}

- (void)setMaxCacheSize:(id)maxCacheSize {
  ENSURE_SINGLE_ARG(maxCacheSize, NSNumber);
  [SDImageCache sharedImageCache].config.maxDiskSize = [TiUtils intValue:maxCacheSize];
}

- (void)setMaxCacheAge:(id)maxCacheAge {
  ENSURE_SINGLE_ARG(maxCacheAge, NSNumber);
  [SDImageCache sharedImageCache].config.maxDiskAge = [TiUtils intValue:maxCacheAge];
}

MAKE_SYSTEM_PROP(CONTENT_MODE_SCALE_TO_FIT, UIViewContentModeScaleToFill)
MAKE_SYSTEM_PROP(CONTENT_MODE_ASPECT_FIT, UIViewContentModeScaleAspectFit)
MAKE_SYSTEM_PROP(CONTENT_MODE_ASPECT_FILL, UIViewContentModeScaleAspectFill)
MAKE_SYSTEM_PROP(CONTENT_MODE_REDRAW, UIViewContentModeRedraw)
MAKE_SYSTEM_PROP(CONTENT_MODE_CENTER, UIViewContentModeCenter)
MAKE_SYSTEM_PROP(CONTENT_MODE_TOP, UIViewContentModeTop)
MAKE_SYSTEM_PROP(CONTENT_MODE_BOTTOM, UIViewContentModeBottom)
MAKE_SYSTEM_PROP(CONTENT_MODE_LEFT, UIViewContentModeLeft)
MAKE_SYSTEM_PROP(CONTENT_MODE_RIGHT, UIViewContentModeRight)
MAKE_SYSTEM_PROP(CONTENT_MODE_TOP_LEFT, UIViewContentModeTopLeft)
MAKE_SYSTEM_PROP(CONTENT_MODE_TOP_RIGHT, UIViewContentModeTopRight)
MAKE_SYSTEM_PROP(CONTENT_MODE_BOTTOM_LEFT, UIViewContentModeBottomLeft)
MAKE_SYSTEM_PROP(CONTENT_MODE_BOTTOM_RIGHT, UIViewContentModeBottomRight)

@end
