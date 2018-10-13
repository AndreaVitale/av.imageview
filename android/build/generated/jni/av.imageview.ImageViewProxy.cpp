/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2017 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "av.imageview.ImageViewProxy.h"

#include "AndroidUtil.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "TypeConverter.h"
#include "V8Util.h"


#include "org.appcelerator.titanium.proxy.TiViewProxy.h"

#define TAG "ImageViewProxy"

using namespace v8;

namespace av {
namespace imageview {
	namespace imageviewandroid {


Persistent<FunctionTemplate> ImageViewProxy::proxyTemplate;
jclass ImageViewProxy::javaClass = NULL;

ImageViewProxy::ImageViewProxy() : titanium::Proxy()
{
}

void ImageViewProxy::bindProxy(Local<Object> exports, Local<Context> context)
{
	Isolate* isolate = context->GetIsolate();

	Local<FunctionTemplate> pt = getProxyTemplate(isolate);

	v8::TryCatch tryCatch(isolate);
	Local<Function> constructor;
	MaybeLocal<Function> maybeConstructor = pt->GetFunction(context);
	if (!maybeConstructor.ToLocal(&constructor)) {
		titanium::V8Util::fatalException(isolate, tryCatch);
		return;
	}

	Local<String> nameSymbol = NEW_SYMBOL(isolate, "ImageView"); // use symbol over string for efficiency
	exports->Set(nameSymbol, constructor);
}

void ImageViewProxy::dispose(Isolate* isolate)
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Reset();
	}

	titanium::TiViewProxy::dispose(isolate);
}

Local<FunctionTemplate> ImageViewProxy::getProxyTemplate(Isolate* isolate)
{
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate.Get(isolate);
	}

	LOGD(TAG, "ImageViewProxy::getProxyTemplate()");

	javaClass = titanium::JNIUtil::findClass("av/imageview/ImageViewProxy");
	EscapableHandleScope scope(isolate);

	// use symbol over string for efficiency
	Local<String> nameSymbol = NEW_SYMBOL(isolate, "ImageView");

	Local<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(isolate,
		titanium::TiViewProxy::getProxyTemplate(isolate)
, javaClass, nameSymbol);

	proxyTemplate.Reset(isolate, t);
	t->Set(titanium::Proxy::inheritSymbol.Get(isolate),
		FunctionTemplate::New(isolate, titanium::Proxy::inherit<ImageViewProxy>));

	// Method bindings --------------------------------------------------------
	titanium::SetProtoMethod(isolate, t, "setHandleCookies", ImageViewProxy::setHandleCookies);
	titanium::SetProtoMethod(isolate, t, "getLoadingIndicator", ImageViewProxy::getLoadingIndicator);
	titanium::SetProtoMethod(isolate, t, "setRequestHeader", ImageViewProxy::setRequestHeader);
	titanium::SetProtoMethod(isolate, t, "getContentMode", ImageViewProxy::getContentMode);
	titanium::SetProtoMethod(isolate, t, "getDefaultImage", ImageViewProxy::getDefaultImage);
	titanium::SetProtoMethod(isolate, t, "setMemoryCacheEnabled", ImageViewProxy::setMemoryCacheEnabled);
	titanium::SetProtoMethod(isolate, t, "getMemoryCacheEnabled", ImageViewProxy::getMemoryCacheEnabled);
	titanium::SetProtoMethod(isolate, t, "setTimeout", ImageViewProxy::setTimeout);
	titanium::SetProtoMethod(isolate, t, "getBrokenLinkImage", ImageViewProxy::getBrokenLinkImage);
	titanium::SetProtoMethod(isolate, t, "getRounded", ImageViewProxy::getRounded);
	titanium::SetProtoMethod(isolate, t, "setBrokenLinkImage", ImageViewProxy::setBrokenLinkImage);
	titanium::SetProtoMethod(isolate, t, "setLoadingIndicatorColor", ImageViewProxy::setLoadingIndicatorColor);
	titanium::SetProtoMethod(isolate, t, "setRounded", ImageViewProxy::setRounded);
	titanium::SetProtoMethod(isolate, t, "setContentMode", ImageViewProxy::setContentMode);
	titanium::SetProtoMethod(isolate, t, "setDefaultImage", ImageViewProxy::setDefaultImage);
	titanium::SetProtoMethod(isolate, t, "setLoadingIndicator", ImageViewProxy::setLoadingIndicator);
	titanium::SetProtoMethod(isolate, t, "getLoadingIndicatorColor", ImageViewProxy::getLoadingIndicatorColor);
	titanium::SetProtoMethod(isolate, t, "getImage", ImageViewProxy::getImage);
	titanium::SetProtoMethod(isolate, t, "setImage", ImageViewProxy::setImage);
	titanium::SetProtoMethod(isolate, t, "getHandleCookies", ImageViewProxy::getHandleCookies);

	Local<ObjectTemplate> prototypeTemplate = t->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = t->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------

	// Dynamic properties -----------------------------------------------------
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "image"),
			ImageViewProxy::getter_image,
			ImageViewProxy::setter_image,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "contentMode"),
			ImageViewProxy::getter_contentMode,
			ImageViewProxy::setter_contentMode,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "loadingIndicator"),
			ImageViewProxy::getter_loadingIndicator,
			ImageViewProxy::setter_loadingIndicator,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "rounded"),
			ImageViewProxy::getter_rounded,
			ImageViewProxy::setter_rounded,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "handleCookies"),
			ImageViewProxy::getter_handleCookies,
			ImageViewProxy::setter_handleCookies,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "loadingIndicatorColor"),
			ImageViewProxy::getter_loadingIndicatorColor,
			ImageViewProxy::setter_loadingIndicatorColor,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "memoryCacheEnabled"),
			ImageViewProxy::getter_memoryCacheEnabled,
			ImageViewProxy::setter_memoryCacheEnabled,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "requestHeader"),
			titanium::Proxy::getProperty,
			ImageViewProxy::setter_requestHeader,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "defaultImage"),
			ImageViewProxy::getter_defaultImage,
			ImageViewProxy::setter_defaultImage,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "timeout"),
			titanium::Proxy::getProperty,
			ImageViewProxy::setter_timeout,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "brokenLinkImage"),
			ImageViewProxy::getter_brokenLinkImage,
			ImageViewProxy::setter_brokenLinkImage,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);

	// Accessors --------------------------------------------------------------
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "defaultImage"),
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "getDefaultImage", titanium::Proxy::getProperty, NEW_SYMBOL(isolate, "defaultImage"));
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "setDefaultImage", titanium::Proxy::onPropertyChanged, NEW_SYMBOL(isolate, "defaultImage"));
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "brokenLinkImage"),
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "getBrokenLinkImage", titanium::Proxy::getProperty, NEW_SYMBOL(isolate, "brokenLinkImage"));
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "setBrokenLinkImage", titanium::Proxy::onPropertyChanged, NEW_SYMBOL(isolate, "brokenLinkImage"));
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "image"),
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "getImage", titanium::Proxy::getProperty, NEW_SYMBOL(isolate, "image"));
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "setImage", titanium::Proxy::onPropertyChanged, NEW_SYMBOL(isolate, "image"));
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "contentMode"),
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "getContentMode", titanium::Proxy::getProperty, NEW_SYMBOL(isolate, "contentMode"));
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "setContentMode", titanium::Proxy::onPropertyChanged, NEW_SYMBOL(isolate, "contentMode"));
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "enableMemoryCache"),
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "getEnableMemoryCache", titanium::Proxy::getProperty, NEW_SYMBOL(isolate, "enableMemoryCache"));
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "setEnableMemoryCache", titanium::Proxy::onPropertyChanged, NEW_SYMBOL(isolate, "enableMemoryCache"));
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "loadingIndicator"),
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "getLoadingIndicator", titanium::Proxy::getProperty, NEW_SYMBOL(isolate, "loadingIndicator"));
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "setLoadingIndicator", titanium::Proxy::onPropertyChanged, NEW_SYMBOL(isolate, "loadingIndicator"));
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "rounded"),
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "getRounded", titanium::Proxy::getProperty, NEW_SYMBOL(isolate, "rounded"));
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "setRounded", titanium::Proxy::onPropertyChanged, NEW_SYMBOL(isolate, "rounded"));
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "requestHeader"),
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "getRequestHeader", titanium::Proxy::getProperty, NEW_SYMBOL(isolate, "requestHeader"));
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "setRequestHeader", titanium::Proxy::onPropertyChanged, NEW_SYMBOL(isolate, "requestHeader"));
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "handleCookies"),
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "getHandleCookies", titanium::Proxy::getProperty, NEW_SYMBOL(isolate, "handleCookies"));
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "setHandleCookies", titanium::Proxy::onPropertyChanged, NEW_SYMBOL(isolate, "handleCookies"));
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "dontAnimate"),
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "getDontAnimate", titanium::Proxy::getProperty, NEW_SYMBOL(isolate, "dontAnimate"));
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "setDontAnimate", titanium::Proxy::onPropertyChanged, NEW_SYMBOL(isolate, "dontAnimate"));

	return scope.Escape(t);
}

// Methods --------------------------------------------------------------------
void ImageViewProxy::setHandleCookies(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setHandleCookies()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setHandleCookies", "(Ljava/lang/Boolean;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setHandleCookies' with signature '(Ljava/lang/Boolean;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setHandleCookies: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	bool isNew_0;

	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void ImageViewProxy::getLoadingIndicator(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getLoadingIndicator()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getLoadingIndicator", "()Ljava/lang/Boolean;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getLoadingIndicator' with signature '()Ljava/lang/Boolean;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ImageViewProxy::setRequestHeader(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setRequestHeader()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setRequestHeader", "(Ljava/util/HashMap;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setRequestHeader' with signature '(Ljava/util/HashMap;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setRequestHeader: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	bool isNew_0;

	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void ImageViewProxy::getContentMode(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getContentMode()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getContentMode", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getContentMode' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ImageViewProxy::getDefaultImage(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getDefaultImage()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getDefaultImage", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getDefaultImage' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ImageViewProxy::setMemoryCacheEnabled(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setMemoryCacheEnabled()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setMemoryCacheEnabled", "(Ljava/lang/Boolean;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setMemoryCacheEnabled' with signature '(Ljava/lang/Boolean;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setMemoryCacheEnabled: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	bool isNew_0;

	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void ImageViewProxy::getMemoryCacheEnabled(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getMemoryCacheEnabled()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getMemoryCacheEnabled", "()Ljava/lang/Boolean;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getMemoryCacheEnabled' with signature '()Ljava/lang/Boolean;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ImageViewProxy::setTimeout(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setTimeout()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setTimeout", "(I)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setTimeout' with signature '(I)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setTimeout: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	

		if ((titanium::V8Util::isNaN(isolate, args[0]) && !args[0]->IsUndefined()) || args[0]->ToString(isolate)->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		}
	if (!args[0]->IsNull()) {
		Local<Number> arg_0 = args[0]->ToNumber(isolate);
		jArguments[0].i =
			titanium::TypeConverter::jsNumberToJavaInt(
				env, arg_0);
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void ImageViewProxy::getBrokenLinkImage(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getBrokenLinkImage()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getBrokenLinkImage", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getBrokenLinkImage' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ImageViewProxy::getRounded(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getRounded()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getRounded", "()Z");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getRounded' with signature '()Z'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jboolean jResult = (jboolean)env->CallBooleanMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}


	Local<Boolean> v8Result = titanium::TypeConverter::javaBooleanToJsBoolean(isolate, env, jResult);



	args.GetReturnValue().Set(v8Result);

}
void ImageViewProxy::setBrokenLinkImage(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setBrokenLinkImage()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setBrokenLinkImage", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setBrokenLinkImage' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setBrokenLinkImage: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	

	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void ImageViewProxy::setLoadingIndicatorColor(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setLoadingIndicatorColor()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setLoadingIndicatorColor", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setLoadingIndicatorColor' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setLoadingIndicatorColor: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	

	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void ImageViewProxy::setRounded(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setRounded()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setRounded", "(Z)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setRounded' with signature '(Z)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setRounded: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	if (!args[0]->IsBoolean() && !args[0]->IsNull()) {
		const char *error = "Invalid value, expected type Boolean.";
		LOGE(TAG, error);
		titanium::JSException::Error(isolate, error);
		return;
	}
	

	if (!args[0]->IsNull()) {
		Local<Boolean> arg_0 = args[0]->ToBoolean(isolate);
		jArguments[0].z =
			titanium::TypeConverter::jsBooleanToJavaBoolean(
				env, arg_0);
	} else {
		jArguments[0].z = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void ImageViewProxy::setContentMode(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setContentMode()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setContentMode", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setContentMode' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setContentMode: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	

	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void ImageViewProxy::setDefaultImage(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setDefaultImage()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setDefaultImage", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setDefaultImage' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setDefaultImage: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	

	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void ImageViewProxy::setLoadingIndicator(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setLoadingIndicator()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setLoadingIndicator", "(Ljava/lang/Boolean;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setLoadingIndicator' with signature '(Ljava/lang/Boolean;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setLoadingIndicator: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	bool isNew_0;

	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void ImageViewProxy::getLoadingIndicatorColor(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getLoadingIndicatorColor()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getLoadingIndicatorColor", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getLoadingIndicatorColor' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ImageViewProxy::getImage(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getImage()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getImage", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getImage' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ImageViewProxy::setImage(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setImage()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setImage", "(Ljava/lang/Object;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setImage' with signature '(Ljava/lang/Object;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setImage: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	bool isNew_0;

	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void ImageViewProxy::getHandleCookies(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getHandleCookies()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getHandleCookies", "()Ljava/lang/Boolean;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getHandleCookies' with signature '()Ljava/lang/Boolean;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}

// Dynamic property accessors -------------------------------------------------

void ImageViewProxy::getter_image(Local<Name> property, const PropertyCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getImage", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getImage' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}

void ImageViewProxy::setter_image(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, image wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setImage", "(Ljava/lang/Object;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setImage' with signature '(Ljava/lang/Object;)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	bool isNew_0;

	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




}


void ImageViewProxy::getter_contentMode(Local<Name> property, const PropertyCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getContentMode", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getContentMode' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}

void ImageViewProxy::setter_contentMode(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, contentMode wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setContentMode", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setContentMode' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	

	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




}


void ImageViewProxy::getter_loadingIndicator(Local<Name> property, const PropertyCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getLoadingIndicator", "()Ljava/lang/Boolean;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getLoadingIndicator' with signature '()Ljava/lang/Boolean;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}

void ImageViewProxy::setter_loadingIndicator(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, loadingIndicator wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setLoadingIndicator", "(Ljava/lang/Boolean;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setLoadingIndicator' with signature '(Ljava/lang/Boolean;)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	bool isNew_0;

	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




}


void ImageViewProxy::getter_rounded(Local<Name> property, const PropertyCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getRounded", "()Z");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getRounded' with signature '()Z'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jboolean jResult = (jboolean)env->CallBooleanMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}


	Local<Boolean> v8Result = titanium::TypeConverter::javaBooleanToJsBoolean(isolate, env, jResult);



	args.GetReturnValue().Set(v8Result);

}

void ImageViewProxy::setter_rounded(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, rounded wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setRounded", "(Z)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setRounded' with signature '(Z)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	if (!value->IsBoolean() && !value->IsNull()) {
		const char *error = "Invalid value, expected type Boolean.";
		LOGE(TAG, error);
	}
	

	if (!value->IsNull()) {
		Local<Boolean> arg_0 = value->ToBoolean(isolate);
		jArguments[0].z =
			titanium::TypeConverter::jsBooleanToJavaBoolean(
				env, arg_0);
	} else {
		jArguments[0].z = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




}


void ImageViewProxy::getter_handleCookies(Local<Name> property, const PropertyCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getHandleCookies", "()Ljava/lang/Boolean;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getHandleCookies' with signature '()Ljava/lang/Boolean;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}

void ImageViewProxy::setter_handleCookies(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, handleCookies wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setHandleCookies", "(Ljava/lang/Boolean;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setHandleCookies' with signature '(Ljava/lang/Boolean;)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	bool isNew_0;

	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




}


void ImageViewProxy::getter_loadingIndicatorColor(Local<Name> property, const PropertyCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getLoadingIndicatorColor", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getLoadingIndicatorColor' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}

void ImageViewProxy::setter_loadingIndicatorColor(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, loadingIndicatorColor wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setLoadingIndicatorColor", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setLoadingIndicatorColor' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	

	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




}


void ImageViewProxy::getter_memoryCacheEnabled(Local<Name> property, const PropertyCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getMemoryCacheEnabled", "()Ljava/lang/Boolean;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getMemoryCacheEnabled' with signature '()Ljava/lang/Boolean;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}

void ImageViewProxy::setter_memoryCacheEnabled(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, memoryCacheEnabled wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setMemoryCacheEnabled", "(Ljava/lang/Boolean;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setMemoryCacheEnabled' with signature '(Ljava/lang/Boolean;)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	bool isNew_0;

	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




}



void ImageViewProxy::setter_requestHeader(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, requestHeader wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setRequestHeader", "(Ljava/util/HashMap;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setRequestHeader' with signature '(Ljava/util/HashMap;)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	bool isNew_0;

	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, args);
}


void ImageViewProxy::getter_defaultImage(Local<Name> property, const PropertyCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getDefaultImage", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getDefaultImage' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}

void ImageViewProxy::setter_defaultImage(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, defaultImage wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setDefaultImage", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setDefaultImage' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	

	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




}



void ImageViewProxy::setter_timeout(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, timeout wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setTimeout", "(I)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setTimeout' with signature '(I)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	

		if ((titanium::V8Util::isNaN(isolate, value) && !value->IsUndefined()) || value->ToString(isolate)->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
		}
	if (!value->IsNull()) {
		Local<Number> arg_0 = value->ToNumber(isolate);
		jArguments[0].i =
			titanium::TypeConverter::jsNumberToJavaInt(
				env, arg_0);
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, args);
}


void ImageViewProxy::getter_brokenLinkImage(Local<Name> property, const PropertyCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "getBrokenLinkImage", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getBrokenLinkImage' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}

void ImageViewProxy::setter_brokenLinkImage(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, brokenLinkImage wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ImageViewProxy::javaClass, "setBrokenLinkImage", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setBrokenLinkImage' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	

	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




}



	} // namespace imageviewandroid
} // imageview
} // av
