#!/bin/bash

echo -n "Enter one or more values: "
read
echo $REPLY
for i in $REPLY;do 
	echo $i
done
