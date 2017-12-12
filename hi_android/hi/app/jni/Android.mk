TARGET_ARCH_ABI := armeabi-v7a
LOCAL_PATH := $(call my-dir)
#include $(CLEAR_VARS)
#LOCAL_MODULE    := sqlite
#LOCAL_SRC_FILES := libsqlite.so
#LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..
#include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE    := foma
LOCAL_SRC_FILES := libfoma.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE    := hilib
LOCAL_SRC_FILES := libhilib.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE    := jhi
LOCAL_SRC_FILES := jhi.cpp
#LOCAL_SHARED_LIBRARIES := sqlite foma hilib
LOCAL_SHARED_LIBRARIES := foma hilib
LOCAL_C_INCLUDES += ${ANDROID_NDK}/sources/cxx-stl/llvm-libc++/libcxx/include
LOCAL_LDLIBS += -llog
include $(BUILD_SHARED_LIBRARY)
