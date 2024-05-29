#!/bin/bash

select day in mon tue wed exit
do
	case $day in
	mon) echo "Monday";;
	tue) echo "Tuesday";;
	wed) echo "Wednesday";;
	exit) exit;;
	esac
done
