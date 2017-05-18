#!/usr/pkg/bin/bash
bison -o y.tab.c $1;
clang++ -x c++ -std=c++11 -fPIC -U__ANDROID__ -U__EMSCRIPTEN -pedantic -Wall -I/usr/pkg/include -c y.tab.c;
clang++ -shared -o libhilib.so y.tab.o;
