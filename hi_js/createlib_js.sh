#!/usr/pkg/bin/bash

dir=(`dirname $1`);
base=`echo $1|rev|cut -d '/' -f1|rev|cut -d '.' -f1`;
c=$dir'/'$base'.c';
bc=$dir'/'$base'.bc';
bison -o $c $1
em++ -std=c++11 -I$2 $c -o $bc