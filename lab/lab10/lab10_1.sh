#!/bin/bash

func() {
	num=$1
	beg=$((num/2 ))
	while [ $beg -gt 1 ]; do
		if [ $((num%beg)) -eq 0 ]; then
			echo 0
			return 
		fi
		((beg--))
	done
	echo 1
	return 
}

# main 
echo -n "Enter a number: "
read number
if [ $(func number) -eq 1 ]; then
	echo "$number is a prime number"
else
	echo "$number is not a prime number"
fi


