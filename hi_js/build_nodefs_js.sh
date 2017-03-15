#emcc -s EXPORTED_FUNCTIONS="['_hi']" hi.bc libsqlite3.a libfoma.a libz.a libreadline.a -o hi.js

dir=(`dirname $1`);
base=(`dirname $1|rev|cut -d '/' -f1|rev`);
js=$dir'/'$base'.js';
emcc -s EXPORTED_FUNCTIONS="['_hi']" $1 libsqlite3.a libfoma.a libz.a libreadline.a -o $js
