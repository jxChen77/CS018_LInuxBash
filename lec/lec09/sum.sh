#! /bin/bash

sum=0
for i in $(ls)
do
if [ -r $i ]
then
((sum++))
fi
done
echo "$sum files are readble in this dir"
