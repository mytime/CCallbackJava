LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := callback
LOCAL_SRC_FILES := callback.c

LOCAL_LDLIBS += -llog

include $(BUILD_SHARED_LIBRARY)
