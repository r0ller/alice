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
		*_out) if [ -n "$(echo "$v"|grep '"gcat":"CON"')" ];
		then out="$out""$(echo "$v"|cut -f3 -d:|cut -f1 -d,)";
		else out="$v";
		fi; 
		;;
	esac;
	c=$(($c+1));
done;
eval "$1"_out='"$out"';