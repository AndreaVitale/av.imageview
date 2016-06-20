/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2013 by Appcelerator, Inc. All Rights Reserved.
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
	explicit ImageViewProxy(jobject javaObject);

	static void bindProxy(v8::Handle<v8::Object> exports);
	static v8::Handle<v8::FunctionTemplate> getProxyTemplate();
	static void dispose();

	static v8::Persistent<v8::FunctionTemplate> proxyTemplate;
	static jclass javaClass;

private:
	// Methods -----------------------------------------------------------
	static v8::Handle<v8::Value> getLoadingIndicator(const v8::Arguments&);
	static v8::Handle<v8::Value> getContentMode(const v8::Arguments&);
	static v8::Handle<v8::Value> getDefaultImage(const v8::Arguments&);
	static v8::Handle<v8::Value> setMemoryCacheEnabled(const v8::Arguments&);
	static v8::Handle<v8::Value> getMemoryCacheEnabled(const v8::Arguments&);
	static v8::Handle<v8::Value> getBrokenLinkImage(const v8::Arguments&);
	static v8::Handle<v8::Value> setBrokenLinkImage(const v8::Arguments&);
	static v8::Handle<v8::Value> setContentMode(const v8::Arguments&);
	static v8::Handle<v8::Value> setDefaultImage(const v8::Arguments&);
	static v8::Handle<v8::Value> setLoadingIndicator(const v8::Arguments&);
	static v8::Handle<v8::Value> getImage(const v8::Arguments&);
	static v8::Handle<v8::Value> setImage(const v8::Arguments&);

	// Dynamic property accessors ----------------------------------------
	static v8::Handle<v8::Value> getter_image(v8::Local<v8::String> property, const v8::AccessorInfo& info);
	static void setter_image(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
	static v8::Handle<v8::Value> getter_contentMode(v8::Local<v8::String> property, const v8::AccessorInfo& info);
	static void setter_contentMode(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
	static v8::Handle<v8::Value> getter_loadingIndicator(v8::Local<v8::String> property, const v8::AccessorInfo& info);
	static void setter_loadingIndicator(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
	static v8::Handle<v8::Value> getter_memoryCacheEnabled(v8::Local<v8::String> property, const v8::AccessorInfo& info);
	static void setter_memoryCacheEnabled(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
	static v8::Handle<v8::Value> getter_defaultImage(v8::Local<v8::String> property, const v8::AccessorInfo& info);
	static void setter_defaultImage(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
	static v8::Handle<v8::Value> getter_brokenLinkImage(v8::Local<v8::String> property, const v8::AccessorInfo& info);
	static void setter_brokenLinkImage(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);

};

			} // namespace imageviewandroid
		} // imageview
		} // av
