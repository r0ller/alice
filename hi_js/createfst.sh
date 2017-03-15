#!/usr/pkg/bin/bash

dir=`dirname $1`;
base=`dirname $1|rev|cut -d '/' -f1|rev`;
fst=$dir'/'$base'.fst';
savestacksh=$dir'/savestack.sh';
echo "save stack $fst" > $savestacksh;
foma -l $1 < $savestacksh