#!/bin/bash

data=22:45:81:93:56
IFS=:

for number in $data; do
	echo $number
done

IFS=':'
for number in $data; do
	echo $number
done
