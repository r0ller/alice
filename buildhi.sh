#!/usr/pkg/bin/bash
g++ -ansi -pedantic -Wall -o hi hi.cpp -L. -lhilib -static -L/usr/pkg/lib -lsqlite3 -lfoma -lz
