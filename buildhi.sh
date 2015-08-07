#!/usr/bin/bash
clang++ -std=c++11 -pedantic -Wall -o hi hi.cpp -L. -lhilib -L/usr/lib -lsqlite3 -lfoma -lz
