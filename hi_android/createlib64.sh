#!/usr/pkg/bin/bash
NDK_TOOLCHAIN=$HOME/ndk-r16b-toolchain64
bison -o y.tab.c $1;
$NDK_TOOLCHAIN/bin/aarch64-linux-android-clang++ -I$NDK_TOOLCHAIN/sysroot/usr/include/android -Ihi_android/hi/app/jni -x c++ -std=c++11 -D__ANDROID__ -pedantic -Wall -c y.tab.c -lstdc++ -latomic;
#rm fifo_hilib;
#mkfifo fifo_hilib;
#cat fifo_hilib > libhilib.so &
$NDK_TOOLCHAIN/bin/aarch64-linux-android-clang++ -shared -Wl,-soname,libhilib.so -o libhilib.so y.tab.o -Lhi_android/hi/app/src/main/jniLibs/arm64-v8a -llog -lfoma -lstdc++ -latomic;
