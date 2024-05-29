#!/bin/bash

while read -r line; do
	wordNum=0
	for i in $line; do
		(( wordNum++ ))
	done
	break
done < $2
Info=( `cat $2` )
numNow=$(($1-1))
until [ $numNow -ge ${#Info[*]} ]; do
	echo ${Info[$numNow]}
	(( numNow += wordNum ))
done
