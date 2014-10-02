if [ -z $constant ]
then
find $source$delim$constant $options $tests -fprint $target
else
find $source$delim$constant $options -fprint $target
fi
