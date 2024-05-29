#!/bin/bash
until (( $(ls|wc -l) == 10 ))
do
	continue
done

echo "10 files are created. They are :"
for files in $(ls); do
	echo $files
done

