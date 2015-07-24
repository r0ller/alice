#!/usr/bin/bash
yacc hi.y;
arm-linux-androideabi-clang++ -x c++ -std=c++11 -pedantic -Wall -c y.tab.c -lstdc++ -latomic;
arm-linux-androideabi-clang++ -shared -o libhilib.so y.tab.o -L. -llog -lsqlite -lfoma -lstdc++ -latomic;
