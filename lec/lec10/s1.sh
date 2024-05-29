#!/bin/bash

echo "All parameters : $@"

select fruit in $@
do
	echo "I like $fruit."
done
