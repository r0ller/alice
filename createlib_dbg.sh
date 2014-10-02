#!/usr/pkg/bin/bash
./createfst.sh;
yacc hi.y;
g++ -g -ansi -pedantic -Wall -I/usr/pkg/include -c y.tab.c -o hilib.o;
ar rcs libhilib.a hilib.o;
