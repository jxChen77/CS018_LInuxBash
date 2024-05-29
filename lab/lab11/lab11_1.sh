#!/bin/bash

echo -n "Enter a username : "
read name

info=("User " " " "UID  " "GID  " "Full name " "Home Dir  " "Shell     ")

IFS=:
UserInfo=$(grep $name <<< cat /etc/passwd)
num=0
for i in $UserInfo; do
	if [ $num = 1 ]; then
		(( num++ ))
		continue
	fi
cat << EOF
${info[num]}: $i
EOF
	((num++))
done
