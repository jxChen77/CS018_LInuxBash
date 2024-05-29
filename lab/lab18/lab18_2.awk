#!/bin/awk -f

BEGIN {
	print"	Name	C	C++	Java	Average"
	print"=============================================="
	maxP=" "
	maxG=0
}
{
	sum=0
	for(i=2; i<=NF; i++)	
		sum+=$i
	ave=sum/(NF-1)
	maxG=ave>maxG ? ave : maxG
	maxP=maxG==ave ? $1 : maxP
	printf "%12s\t%2.0f\t%2.0f\t%2.0f\t%2.2f\n", $1, $2, $3, $4, ave	
}
END {
	print "-------------------------------------------------"
	printf "'%s' has the highest average '%2.2f'\n", maxP, maxG
}
