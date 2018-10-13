# Android.mk for av.imageview
LOCAL_PATH := $(call my-dir)
THIS_DIR := $(LOCAL_PATH)

include $(CLEAR_VARS)

THIS_DIR = $(LOCAL_PATH)
LOCAL_MODULE := av.imageview
LOCAL_CFLAGS := -g "-I$(TI_MOBILE_SDK)/android/native/include"

# https://jira.appcelerator.org/browse/TIMOB-15263
LOCAL_DISABLE_FORMAT_STRING_CHECKS=true

LOCAL_CFLAGS += -Wno-conversion-null -Wno-format-security -Wno-format -Wno-tautological-compare -Wno-unused-result -Wno-deprecated-register
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -ldl -llog -L$(TARGET_OUT) "-L$(TI_MOBILE_SDK)/android/native/libs/$(TARGET_ARCH_ABI)" -lkroll-v8

GEN_DIR := $(realpath .)
GEN_JNI_DIR := $(GEN_DIR)/jni

ABS_SRC_FILES := $(wildcard $(LOCAL_PATH)/*.cpp)
BOOTSTRAP_CPP := $(wildcard $(LOCAL_PATH)/../*Bootstrap.cpp)

LOCAL_SRC_FILES := $(patsubst $(LOCAL_PATH)/%,%,$(ABS_SRC_FILES)) \
	$(patsubst $(LOCAL_PATH)/%,%,$(BOOTSTRAP_CPP))

$(BOOTSTRAP_CPP): $(GEN_DIR)/KrollGeneratedBindings.cpp $(GEN_DIR)/BootstrapJS.cpp

include $(BUILD_SHARED_LIBRARY)
