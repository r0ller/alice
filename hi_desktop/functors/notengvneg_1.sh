echo "printing parameters and their contents for" $1;
unset out;
c=1;
for i in $2;
do 
	p=$(($c+2));
	eval v="\$$p";
	echo name;
	echo $i;
	echo content;
	echo "$v";
	case "$i" in 
		*_out) eval morph="\$"$1"_morphology";
		if [ -z "$morph" ];
		then out="$v";
		else out="$(echo "$v"|sed "s/-path/! -path/g")";
		fi;
		 ;;
	esac;
	c=$(($c+1));
done;
eval "$1"_out='"$out"';