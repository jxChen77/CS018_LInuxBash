#!/bin/bash

Info=("Username" "Password" "User ID" "Group ID" "User Info" "Home" "Shell")
lineNum=0
while read line; do
	(( lineNum++ ))
	echo  "[$lineNum]"
	for i in "${Info[@]}"; do
		realInfo=${line%%:*}
		line=${line:((${#realInfo}+1))}
		echo -n "$i" 
		for _ in `seq ${#i} 9`; do
			echo -n " "
		done
		echo ": $realInfo"
	done
done < /etc/passwd
