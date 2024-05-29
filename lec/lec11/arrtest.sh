#!/bin/bash

fruit[0]="Apple"
fruit[1]="Orange"
fruit[2]="Kiwi"
fruit[3]="Grape"
found=1
for f in ${fruit[@]}; do
	if [ $f == $1 ]; then
		echo "Found: $1"
		found=0
		break
	fi
done 
if [ $found -eq 1 ]; then

	echo "Not Found: $1"
fi

	
