bison -o y.tab.c ../hi.y
em++ -std=c++11 -I../ y.tab.c -o hi.bc
