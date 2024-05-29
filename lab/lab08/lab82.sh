#!/bin/bash

mkdir oldest

copy_file() {
	if ! [ ${1:2} = "oldest" ]; then
		for file in $(find $ls $1 -maxdepth 1 -type f); do
			max=$file
			break
		done
		for file in $(find $ls $1 -maxdepth 1 -type f); do
			if [ $file -ot $max ]; then
				max=$file
			fi
		done
		if [ -n $max ]; then
			cp $max ~/lab/lab8/oldest/
		fi
	fi
}

for dir in $(find $ls -mindepth 1 -maxdepth 2 -type d | sort ); do
	copy_file $dir
done
