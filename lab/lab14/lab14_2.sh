#!/bin/bash

while read -r line; do
	wordNum1=0
	for i in $line; do
		(( wordNum1++ ))
	done
	break
done < $1
while read -r line; do
	wordNum2=0
	for i in $line; do
		(( wordNum2++ ))
	done
	break
done < $2
Info1=(`cat $1`)
Info2=(`cat $2`)
num1=0
num2=0
until [ $num1 -ge ${#Info1[*]} ]; do 
	if [ $num2 -lt ${#Info2[*]} ] && [ ${Info1[$num1]} = ${Info2[$num2]} ]; then
		echo -n ${Info1[$num1]}
		for i in $(seq 1 $((wordNum1-1))); do
			echo -n " ${Info1[$(($i+$num1))]}" 
		done
		for i in $(seq 1 $((wordNum2-1))); do
			echo -n " ${Info2[$(($i+$num2))]}" 
		done
		(( num1+=wordNum1))
        	(( num2+=wordNum2))
	elif [ $num2 -lt ${#Info2[*]} ] && [ ${Info1[$num1]} -gt ${Info2[$num2]} ]; then
		echo -n ${Info2[$num2]}
		 for i in $(seq 1 $((wordNum1-1))); do
                        echo -n " X"
                done
                for i in $(seq 1 $((wordNum2-1))); do
                        echo -n " ${Info2[$(($i+$num2))]}"
                done
		(( num2+=wordNum2))
	elif  [ $num2 -ge ${#Info2[*]} ] || [ ${Info1[$num1]} -lt ${Info2[$num2]} ];then
		echo -n ${Info1[$num1]}
                for i in $(seq 1 $((wordNum1-1))); do
                        echo -n " ${Info1[$(($i+$num1))]}"
                done
                for i in $(seq 1 $((wordNum2-1))); do
                        echo -n " X"
                done
        	(( num1+=wordNum1))
	fi		
	echo
done
until [ $num2 -ge ${#Info2[*]} ]; do
	echo -n ${Info2[$num2]}
                for i in $(seq 1 $((wordNum1-1))); do
                        echo -n " X"
                done
                for i in $(seq 1 $((wordNum2-1))); do
                        echo -n " ${Info2[$(($i+$num2))]}"
                done
                (( num2+=wordNum2))
        echo
done

