#!/bin/bash

touch member
answer=y

until [[ $answer = n ]]; do
	echo -n "Enter name		: "
	read name
	echo -n "Enter home address	: "
	read -a home
	addr=
	addr+="${home[0]}"
	addr+="${home[1]}"
	addr+="${home[2]}"
	echo -n "Enter Email address	: "
	read email
	echo -n "Enter phone number	: "
	read phone
	
	vaild=1	

	if echo $name | grep -q "^[A-Z][a-z]*\s[A-Z][a-z]*$"; then
		vaild=$vaild
	else
		vaild=0
	fi

	if echo $addr | grep -E "^[1-9][0-9]{1,3}[A-Z][a-z]* ([Aa]ve|[Ss]t|[Bb]lvd)\. ${home[3]} [0-9]{5}-[0-9]{4}$" && grep "${home[3]}" city.txt; then
		vaild=$vaild
	else
        	valid=0
    	fi

	if echo $email | grep -P '^[a-zA-Z0-9._]{8,}@[a-zA-Z]+\.(com|org|edu)$' | grep -P '^(?=.*[a-zA-Z])(?=.*[0-9])' 
	then
		vaild=$vaild
	else
		vaild=0
	fi

	if echo $phone | grep -E "^([0-9]{3}|\([0-9]{3}\)) [0-9]{3}-[0-9]{4}$"; then
		vaild=$vaild
	else
		vaild=0
	fi

	if [ $vaild = 1 ]; then
		echo -e "$name\n${home[*]}\n$email\n$phone" >> member
	fi

	echo
	echo -n "More (y/n)? "
	read answer
	echo
done
