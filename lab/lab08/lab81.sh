#!/bin/bash


count_files() {
  # $1 is the first argument to the function: directory path
  echo "${1:2} - $(find "$1" -maxdepth 1 -type f | wc -l) files"
}

# Output the counts for each specified directory
for file in $(find $ls -mindepth 1 -maxdepth 2 -type d | sort ); do
	count_files $file
done
