#!/bin/bash

findword() {
	lineNum=0
	while read line; do
		IFS=" "
		((lineNum++))
		for word in $line; do
                       	if [ $word = $Findword ]; then
				showWord $Findword "$line"
				echo 
			fi
		done
	done < $fileName
		

}

showWord(){
	if [ $showLine = 1 ]; then
		echo -n -e "\033[1;32m[$lineNum]\033[0m "
	fi
	for word in $2; do
		if [ $word = $1 ]; then
		       echo -n -e "\033[1;31m$word\033[0m "	
	       	else
			echo -n "$word " 
		fi
	done

}

if [ $1 = "-n" ]; then
	showLine=1
	Findword=$2
	fileName=$3
else
	showLine=0
	Findword=$1
	fileName=$2
fi

findword 
