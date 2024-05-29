#!/bin/bash  

inFile=$1
maxCh=`cat $inFile | tr -d ' \n' | tr 'A-Z' 'a-z' |  sed 's/[[:lower:]]/ &/g' | sed 's/ /\n&/g' | sort | uniq -c | sort -r | sed -n '1p' | sed 's/ //g' |  sed 's/[[:lower:]]/ &/g' | cut -d " " -f 2`
maxValue=$(printf "%d" "'$maxCh")
while read -r line; do 
	nowValue=$(printf "%d" "'$line")
	difference=$((maxValue - nowValue))
	isWork=1
	if [ $difference -gt 0 ]; then
		key=$difference
	else
		key=$((26+difference))
	fi
	lab15_1.sh d $key $inFile te2
	cat t2
	for word in `cat te2`; do
		if grep -q $word possibleWords; then
			isWork=$isWork
		else
			isWork=0
			break
		fi
	done
	if [ $isWork -eq 1 ]; then
		break
	fi
done < mostFrequency
echo "key is $key"
rm te2
