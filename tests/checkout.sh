#!/bin/sh
row_nr=0;
output="";
while IFS= read -r line;
	do
		row_nr=$(($row_nr+1));
		echo $line;
		if [ `expr $row_nr % 2` -eq 0 ];
		then
			if [ ! "$output" = "$line" ];
			then
				echo "Line $row_nr does not match the output:";
				echo "$output";
			fi;
		else
			text=$(echo $line|cut -f1 -d'|');
			options=$(echo $line|cut -f2 -d'|');
			output=$(echo $text|./hi $options|tail -2|tr -d '\n' );
		fi;
	done < $1;
echo $line;
if [ ! "$output" = "$line" ];
then
	echo "Line $row_nr does not match the output:";
	echo "$output";
fi;
