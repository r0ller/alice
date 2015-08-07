#!/usr/bin/bash
yacc hi.y;
arm-linux-androideabi-clang++ -x c++ -std=c++11 -D__ANDROID__ -pedantic -Wall -c y.tab.c -lstdc++ -latomic;
arm-linux-androideabi-clang++ -shared -o libhilib.so y.tab.o -Lhi_android/jni -llog -lsqlite -lfoma -lstdc++ -latomic;
