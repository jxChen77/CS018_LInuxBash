#!/bin/bash

echo -n "Please enter a number (1-4): "
read num

case $num in
1)
	echo "You entered 1" ;;
2)
	echo "You entered 2" ;;
3) 
	echo "You entered 3" ;;
4)
	echo "You entered 4" ;;
*)	
	echo "You should enter 1-4" ;;
esac
