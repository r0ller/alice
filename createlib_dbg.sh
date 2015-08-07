#!/usr/bin/bash
./createfst.sh;
yacc hi.y;
clang++ -x c++ -std=c++11 -U__ANDROID__ -g -pedantic -Wall -I/usr/include -I/usr/local/include -c y.tab.c;
clang++ -shared -o libhilib.so y.tab.o;
