#!/usr/pkg/bin/bash
./createfst.sh;
yacc hi.y;
clang++ -std=c++11 -fexceptions -fcxx-exceptions -g -pedantic -Wall -I/usr/pkg/include -c y.tab.c -o hilib.o;
ar rcs libhilib.a hilib.o;
