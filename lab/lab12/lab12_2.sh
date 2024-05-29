#!/bin/bash

files=$(grep "t\?et\{3\}" $1)
for i in $files; do
	echo "file : $i"
	echo "------------------"
	grep "\b[0-9]\{3\}-[0-9]\{3\}-[0-9]\{4\}\b" $i
	echo
done


