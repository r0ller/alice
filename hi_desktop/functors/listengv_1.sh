echo "printing parameters and their contents for" "$1";
unset out;
unset script;
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
if [ "$mood" = "imperative" ]; then
  echo $mood;
  c=1;
  for i in $2;
  do
    echo name;
    echo $i;
    echo content;
    p=$(($c+2));
    eval v="\$$p";
    echo "$v";
    case "$i" in
      *_out) op="$(echo "$v"|cut -c1)";
        if [ "$op" = "\"" ];
        then dirs="$(echo "$v"|tr "\"\"" "\""|tr "\"" " ")";
          for j in $dirs;
          do
            script="$script""find $j;";
          done;
          echo "$script";
          eval "$script";
          exit;
        elif [ "$op" = "|" ];
        then OIFS="$IFS";
          IFS="|";
          v="$(echo "$v"|cut -c2-)";
          for j in $v;
          do
            echo "$j";
            unset path;
            unset options;
            unset script;
            unset linked;
            IFS="&";
            for k in $j;
            do
              echo "$k";
              case "$k" in
                *-path*) if [ "$(echo "$k"|cut -c1)" != "!" ];
                  then path="$path ""$(echo "$k"|sed "s/-path//g")";
                  else options="$options ""$(echo "$k"|sed "s/ \"/ \"*\//g")";
                  options="${options%?}""/*\"";
                  fi;
                  ;;
                *-L*) if [ "$(echo "$k"|cut -c1)" != "!" ];
                  then linked=true;
                  fi;
                  ;;
                *) options="$options ""$k";
                  ;;
              esac;
            done;
            if [ -z "$path" ];
            then path="./";
            fi;
            if [ -z "$linked" ];
            then script="find ""$path ""-type f $options";
            else script="links=\"\$(find ""$path ""-type l $options)\";for l in \$links;do echo \"\$l\"|xargs readlink -f;done;";
            fi;
            echo "$script";
            eval "$script";
            IFS="|";
          done;
          exit;
        elif [ -z "$op" ];
        then script="find ./ -type f";
          echo "$script";
          eval "$script";
        fi;
        ;;
    esac;
    c=$(($c+1));
  done;
  eval "$1"_out="$1";
elif [ "$mood" = "interrogative" ]; then
  echo $mood;
elif [ "$mood" = "indicative" ]; then
  echo $mood;
fi;
