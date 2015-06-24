#!/usr/pkg/bin/bash
./createfst.sh;
yacc hi.y;
clang++ -x c++ -std=c++11 -g -pedantic -Wall -I/usr/pkg/include -c y.tab.c;
clang++ -shared -o libhilib.so y.tab.o;