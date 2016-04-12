#!/usr/pkg/bin/bash
./createfst.sh;
bison -o y.tab.c hi.y;
clang++ -x c++ -std=c++11 -pedantic -Wall -I/usr/pkg/include -c y.tab.c;
clang++ -shared -o libhilib.so y.tab.o;
