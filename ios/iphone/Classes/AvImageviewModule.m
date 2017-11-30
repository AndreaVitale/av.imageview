/**
 * This module was developed by
 * Andrea Vitale
 * vitale.andrea@me.com
 *
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2016 by Appcelerator, Inc. All Rights Reserved.
 */

#import "AvImageviewModule.h"
#import "TiBase.h"
#import "TiHost.h"
#import "TiUtils.h"

@implementation AvImageviewModule

#pragma mark Internal

// this is generated for your module, please do not change it
-(id)moduleGUID
{
	return @"ddffa9fa-4366-40f0-9031-d32000a82138";
}

// this is generated for your module, please do not change it
-(NSString*)moduleId
{
	return @"av.imageview";
}

#pragma mark Lifecycle

-(void)startup
{
	// this method is called when the module is first loaded
	// you *must* call the superclass
	[super startup];

	NSLog(@"[INFO] %@ loaded",self);
}

-(void)shutdown:(id)sender
{
	// this method is called when the module is being unloaded
	// typically this is during shutdown. make sure you don't do too
	// much processing here or the app will be quit forceably

	// you *must* call the superclass
	[super shutdown:sender];
}

#pragma mark Internal Memory Management

-(void)didReceiveMemoryWarning:(NSNotification*)notification
{
	// optionally release any resources that can be dynamically
	// reloaded once memory is available - such as caches
	[super didReceiveMemoryWarning:notification];
}

#pragma mark Listener Notifications

-(void)_listenerAdded:(NSString *)type count:(int)count
{
	if (count == 1 && [type isEqualToString:@"my_event"])
	{
		// the first (of potentially many) listener is being added
		// for event named 'my_event'
	}
}

-(void)_listenerRemoved:(NSString *)type count:(int)count
{
	if (count == 0 && [type isEqualToString:@"my_event"])
	{
		// the last listener called for event named 'my_event' has
		// been removed, we can optionally clean up any resources
		// since no body is listening at this point for that event
	}
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
