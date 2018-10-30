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
		PROPERTIES_*_out) if [ -n "$out" ];
		then out="$(echo "$v"|sed "s/|/$out/g")";
		else out="$v";
		fi;
		break; 
		;;
		*_out) out="$out""$v"; 
		;;
	esac;
	c=$(($c+1));
done;
eval "$1"_out='"$out"';