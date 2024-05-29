#!/bin/bash

area_R() {
	echo "You choose rectangle"
	echo -n "Enter width: "
	read width
	echo -n "Enter height: "
	read height
	area=$((width*height))
	return 
}

area_C(){
	echo "You choose circle"
	echo -n "Enter radius: "
	read r
	area=$((3*r*r))
	return 
}

# main 
echo -n "Rectangle or Circlr (R/C) : "
read choose
if [ $choose = R ]; then
	area_R
elif [ $choose = C ]; then
	area_C
fi
echo "The area is $area"
