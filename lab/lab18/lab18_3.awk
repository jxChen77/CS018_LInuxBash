#!/bin/awk -f

BEGIN {
	files=0
	dic=0
}

{
	if (NR > 1){ 
		if (system("! test -d " $NF)  ) {
		 	printf "<Directory Name : %s>\n", $NF;
			dic++;
		}
		else {
			printf "<File Name : %s>\n", $NF;
			files++;
		}
		size=$5;
		if (size<1024) 
			printf "size :%4.0fB\n", size;
		else if (size % 1024 == 0) 
			printf "size : %.0fKB\n", size/1024;
		else
			printf "size : %fKB\n", size/1024;
		print "last_modified :",$6, $7, $8;
		print "Owner : " $3;
		print "Permission: " $1;
		print "--------------------------------------";
	}
}
END{
	print "Number of files :",files
	print "Number of directories :",dic
	print "Total number of files :",files+dic
}
