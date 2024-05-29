#!/bin/bash

echo "All parameters : $@"

select fruit in $@
do
	if [ $fruit == 'exit' ]
	then break
	fi
	echo "I like $fruit."
done
