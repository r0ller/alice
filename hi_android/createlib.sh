#!/usr/pkg/bin/bash
bison -o y.tab.c hi.y;
arm-linux-androideabi-clang++ -x c++ -std=c++11 -D__ANDROID__ -pedantic -Wall -c y.tab.c -lstdc++ -latomic;
rm fifo_hilib;
mkfifo fifo_hilib;
cat fifo_hilib > libhilib.so &
arm-linux-androideabi-clang++ -shared -o fifo_hilib y.tab.o -Lhi_android/jni -llog -lfoma -lstdc++ -latomic;
