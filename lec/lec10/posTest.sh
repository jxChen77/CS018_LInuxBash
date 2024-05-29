#!/bin/bash
num=0
sum=0
sen=""
for i in $@
do 
	if (( i >= 10 ))
then 
	(( num++ ))
	sen+=$i
	sen+=" "
	(( sum+=i))
fi
done
echo "There are $num numbers greater than or equal to 10"
echo $sen
echo $sum


