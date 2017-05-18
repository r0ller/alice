#!/usr/pkg/bin/bash

dir=`dirname $1`;
base=`echo $1|rev|cut -d '/' -f1|rev|cut -d '.' -f1`;
fst=$dir'/'$base'.fst';
savestacksh=$dir'/savestack.sh';
echo "save stack $fst" > $savestacksh;
cd $dir;#in order to allow specifying the lexc filenames only w/o path in the foma file
export LD_LIBRARY_PATH=/usr/pkg/lib;
foma -l $1 < $savestacksh;
