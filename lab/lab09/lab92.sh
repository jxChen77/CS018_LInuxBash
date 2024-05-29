#!/bin/bash

mkdir 2024_Mar
mkdir 2024_Mar/week-{1..4}

Dir=$(pwd)
filec=$Dir"/2024_Mar/week-1"
filepy=$Dir"/2024_Mar/week-2"
filesDir=$Dir"/files"
for i in $(ls files); do
	cd $filesDir'/'$i
	for file in $(ls); do
		newName=${file%.*}
		if [ ${newName##*.} = 'c' ]; then
			cp $file $filec'/'$newName
		elif [ ${newName##*.} = 'py' ]; then
			cp $file $filepy'/'$newName
		fi

	done
done


