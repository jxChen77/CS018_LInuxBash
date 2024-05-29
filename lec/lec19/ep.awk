#!/bin/awk -f

BEGIN{
	printf "%20s %20s %20s\n", "User Name", "Home", "Shell"
	for (i = 1; i <= 65; i++)
        	printf "="
    	printf "\n"
	FS=":"
}
{printf "%2s %20s %20s %20s\n", NR, $1, $6, $7 } 
END{
	print "---------------------------------------------"
	printf "There are %2s users\n", NR
	print "---------------------------------------------"
}
