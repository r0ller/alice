bison -o y.tab.c ../hi.y
em++ -std=c++11 -D__EMBEDNODB__ -I../ y.tab.c -o hi.bc
