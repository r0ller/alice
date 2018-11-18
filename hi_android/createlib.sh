#!/usr/pkg/bin/bash
NDK_TOOLCHAIN=$HOME/ndk-r10e-toolchain32
bison -o y.tab.c $1;
$NDK_TOOLCHAIN/bin/arm-linux-androideabi-clang++ -I$NDK_TOOLCHAIN/sysroot/usr/include/android -Ihi_android/hi/app/jni -x c++ -std=c++11 -D__ANDROID__ -pedantic -Wall -c y.tab.c -lstdc++ -latomic;
rm fifo_hilib;
mkfifo fifo_hilib;
cat fifo_hilib > libhilib.so &
$NDK_TOOLCHAIN/bin/arm-linux-androideabi-clang++ -shared -Wl,-soname,libhilib.so -o fifo_hilib y.tab.o -Lhi_android/hi/app/src/main/jniLibs/armeabi-v7a -llog -lfoma -lstdc++ -latomic;
