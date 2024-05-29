#!/bin/bash

files=${@:2}
echo "You are searching for '$1' in $files"
for i in $files; do 
	echo "$i:`grep -c $1 $i`" 
done
