#!/bin/awk -f
BEGIN {
	printf "     Name   C  C++ Java|| Max\n"
	printf "==============================\n"
}
{
	max = 0;
	printf "%10s", $1
	for(i=2; i < NF+1; i++) {
		printf "%4d", $i
		if ($i >= max)
			max = $i;
	}
	printf " ||%4d\n", max
}END{
	printf "==============================\n"
}
