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
elif [ $mood = "interrogative" ]; then 
	echo $mood;
elif [ $mood = "indicative" ]; then 
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
      *_out) if [ -n "$(echo "$v"|grep '"gcat":"CON"')" ];
      then out="$out""$(echo "$v"|cut -f3 -d:|cut -f1 -d,|tr -d \")";
      else out="$v";
      fi;
      ;;
    esac;
    c=$(($c+1));
  done;
  echo "Inserting c_value:"$out;
  unescaped_analysis=$(echo "$analysis_deps"|tr -d \\\\);
  echo "$unescaped_analysis";
  echo $1;
  /home/llencses/projects/hi_netbsd/hi/build/hi -c /home/llencses/projects/hi_netbsd/hi/build/hi_desktop/hi.db "$unescaped_analysis" $1 $out;
fi;
