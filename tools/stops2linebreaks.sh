sed -i 's/\.\([[:punct:]][^[:space:]]*[[:punct:]] \)/\.'$'\\\n''\1'$'\\\n''/g' $1
sed -i 's/\. \([[:upper:][:punct:]]\)/\.'$'\\\n''\1/g' $1