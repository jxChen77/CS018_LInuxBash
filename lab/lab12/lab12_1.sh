#!/bin/bash

touch list
numberNow=$(ls|wc -w)
numberTarget=`expr $numberNow + 6 `
while [ 0 ] ; do
	if [ $(ls | wc -w) -ge $numberTarget ]; then
		break
	fi
done
for file in $(ls -tr); do
	if ! [ $file = 'list' ] && ! [ $file = 'lab12_1.sh' ]; then
		cat >> list <<< $file 
	fi
done
