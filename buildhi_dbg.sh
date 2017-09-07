#!/usr/pkg/bin/bash
clang++ -fstandalone-debug -std=c++11 -g -pedantic -Wall -o hi hi.cpp -L. -Wl,-rpath=$(pwd) -lhilib -L/usr/pkg/lib -lsqlite3 -lfoma -lz
