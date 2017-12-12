NDK_TOOLCHAIN_VERSION := clang
APP_ABI := armeabi-v7a
APP_PLATFORM := android-23
# Instruct to use the static GNU STL implementation
#APP_STL := gnustl_static
APP_STL := c++_static
#  Enable C++11 and exceptions
APP_CPPFLAGS += -std=c++11 -fexceptions
