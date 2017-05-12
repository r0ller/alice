#!/usr/pkg/bin/bash

dir=(`dirname $1`);
base=(`dirname $1|rev|cut -d '/' -f1|rev`);
js=$dir'/'$base'.js';
emcc -s EXPORTED_FUNCTIONS="['_hi']" $1 -L$2 -lsqlite3 -lfoma -lz -lreadline -o $js
