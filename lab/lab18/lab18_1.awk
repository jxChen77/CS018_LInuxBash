#!/bin/awk -f

BEGIN {
	print"	name	max"
	print"-------------------"
}
{
	max=$2
	for(i=2; i<=NF; i++)	
		max = $i > max ? $i : max
	printf "%12s\t%2.0f\n", $1, max	
}

