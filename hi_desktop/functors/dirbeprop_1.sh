echo "printing parameters and their contents for" $1;
unset out;
ordered_args=$(echo $2|tr " " "\n"|sort -t "_" -k 3,3n -k 4,4n);
c=1;
for i in $ordered_args;
do 
	eval v="\$$i";
	echo name;
	echo $i;
	echo content;
	echo "$v";
	case "$i" in 
		*_out) option="$v";
		if [ -z "$out" ];
		then out="$option";
		else out="$out&$option";
		fi; 
		;;
		*_morphology) option="$v";
		if [ -z "$out" ];
		then out="$option";
		else out="$out<$option";
		fi; 
		;;
	esac;
	c=$(($c+1));
done;
eval "$1"_out='"$out"';