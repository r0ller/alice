head -n4 $1>$1_unique;
sed -n '5,$p' $1|sort -u>$1_tail;
cat $1_tail>>$1_unique;