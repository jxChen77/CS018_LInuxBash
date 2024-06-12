#!/bin/awk -f

BEGIN{
	ls -l > m	
	count = 0
	mon=NF-3
}
{

	if $mon == "Jun" 
		printf "%d : %s was created in April.", ++count, $NF;
}END{
	printf "---------------------\n"
	printf "Number of files created in Apr: %d\n", count
}

