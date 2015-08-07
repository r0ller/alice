#!/usr/bin/bash
./createfst.sh;
yacc hi.y;
clang++ -x c++ -std=c++11 -pedantic -Wall -I/usr/include -c y.tab.c;
clang++ -shared -o libhilib.so y.tab.o;
