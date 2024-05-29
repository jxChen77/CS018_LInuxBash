#!/bin/awk -f 

BEGIN {
	printf "Enter a number : "
	getline n < "/dev/stdin"
	
	if ( n%2 == 0)
		printf "%d is even. \n", n
	else 
		printf "%d is odd. \n", n
}
