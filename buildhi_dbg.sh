#!/usr/pkg/bin/bash
clang++ -std=c++11 -fexceptions -fcxx-exceptions -g -pedantic -Wall -o hi hi.cpp -L. -lhilib -static -L/usr/pkg/lib -lsqlite3 -lfoma -lz
