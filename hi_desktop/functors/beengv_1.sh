echo "printing parameters and their contents for" $1;
unset out;
c=1;
mood="";
for i in $2;
do 
	p=$(($c+2));
	eval v="\$$p";
	case "$i" in 
		*_tags) if [ -n "$(echo "$v"|grep 'mood:interrogative')" ]; 
		then mood="interrogative"; 
		elif [ -n "$(echo "$v"|grep 'mood:indicative')" ]; 
		then mood="indicative"; 
		elif [ -n "$(echo "$v"|grep 'mood:imperative')" ]; 
		then mood="imperative"; 
		else echo "error"; 
		fi; 
		;;
		*_morphology) morph="$v";
	esac;
	c=$(($c+1));
done;
if [ $mood = "imperative" ]; then 
echo $mood;
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
elif [ $mood = "interrogative" -a -n "$morph" ]; then 
	echo $mood;
	echo $morph;
	analyses="$(/home/r0ller/hi/build/hi -q test)";
	echo $analyses;
elif [ $mood = "indicative" ]; then 
	echo $mood;
fi;
