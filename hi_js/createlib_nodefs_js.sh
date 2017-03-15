#bison -o y.tab.c ../hi.y
#em++ -std=c++11 -DFS=NODEJS -I../ y.tab.c -o hi.bc

dir=(`dirname $1`);
base=(`dirname $1|rev|cut -d '/' -f1|rev`);
c=$dir'/'$base'.c';
bc=$dir'/'$base'.bc';
bison -o $c $1
em++ -std=c++11 -DFS=NODEJS -I../ $c -o $bc
