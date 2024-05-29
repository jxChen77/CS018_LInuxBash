#!/bin/awk -f
BEGINFILE {
	print "=========Student Score===========" FILENAME 
}
{ print $0} 
END {
	print "================================="
}
