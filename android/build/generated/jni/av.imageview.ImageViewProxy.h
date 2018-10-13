/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2016 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This is generated, do not edit by hand. **/

#include <jni.h>

#include "Proxy.h"

namespace av {
namespace imageview {
	namespace imageviewandroid {

class ImageViewProxy : public titanium::Proxy
{
public:
	explicit ImageViewProxy();

	static void bindProxy(v8::Local<v8::Object>, v8::Local<v8::Context>);
	static v8::Local<v8::FunctionTemplate> getProxyTemplate(v8::Isolate*);
	static void dispose(v8::Isolate*);

	static jclass javaClass;

private:
	static v8::Persistent<v8::FunctionTemplate> proxyTemplate;

	// Methods -----------------------------------------------------------
	static void setHandleCookies(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getDontAnimate(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getLoadingIndicator(const v8::FunctionCallbackInfo<v8::Value>&);
	static void setRequestHeader(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getContentMode(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getDefaultImage(const v8::FunctionCallbackInfo<v8::Value>&);
	static void setDontAnimate(const v8::FunctionCallbackInfo<v8::Value>&);
	static void setMemoryCacheEnabled(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getMemoryCacheEnabled(const v8::FunctionCallbackInfo<v8::Value>&);
	static void setTimeout(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getBrokenLinkImage(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getRounded(const v8::FunctionCallbackInfo<v8::Value>&);
	static void setBrokenLinkImage(const v8::FunctionCallbackInfo<v8::Value>&);
	static void setLoadingIndicatorColor(const v8::FunctionCallbackInfo<v8::Value>&);
	static void setRounded(const v8::FunctionCallbackInfo<v8::Value>&);
	static void setContentMode(const v8::FunctionCallbackInfo<v8::Value>&);
	static void setDefaultImage(const v8::FunctionCallbackInfo<v8::Value>&);
	static void setLoadingIndicator(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getLoadingIndicatorColor(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getImage(const v8::FunctionCallbackInfo<v8::Value>&);
	static void setImage(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getHandleCookies(const v8::FunctionCallbackInfo<v8::Value>&);

	// Dynamic property accessors ----------------------------------------
	static void getter_image(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info);
	static void setter_image(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);
	static void getter_loadingIndicator(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info);
	static void setter_loadingIndicator(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);
	static void getter_handleCookies(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info);
	static void setter_handleCookies(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);
	static void getter_loadingIndicatorColor(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info);
	static void setter_loadingIndicatorColor(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);
	static void getter_memoryCacheEnabled(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info);
	static void setter_memoryCacheEnabled(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);
	static void setter_timeout(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);
	static void getter_brokenLinkImage(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info);
	static void setter_brokenLinkImage(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);
	static void getter_dontAnimate(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info);
	static void setter_dontAnimate(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);
	static void getter_contentMode(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info);
	static void setter_contentMode(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);
	static void getter_rounded(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info);
	static void setter_rounded(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);
	static void setter_requestHeader(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);
	static void getter_defaultImage(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info);
	static void setter_defaultImage(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);

};

	} // namespace imageviewandroid
} // imageview
} // av
