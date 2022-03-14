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
	esac;
	c=$(($c+1));
done;
if [ $mood = "imperative" ]; then 
echo $mood;
eval "$1"_out="executable";
elif [ $mood = "interrogative" ]; then 
	echo $mood;
elif [ $mood = "indicative" ]; then 
	echo $mood;
fi;
