#!/usr/pkg/bin/bash
bison -o y.tab.c $1;
arm-linux-androideabi-clang++ -x c++ -std=c++11 -D__ANDROID__ -pedantic -Wall -c y.tab.c -lstdc++ -latomic;
rm fifo_hilib;
mkfifo fifo_hilib;
cat fifo_hilib > libhilib.so &
arm-linux-androideabi-clang++ -shared -Wl,-soname,libhilib.so -o fifo_hilib y.tab.o -Lhi_android/hi/app/jni -llog -lfoma -lstdc++ -latomic;
