#!/bin/bash

select operation in $@; do
	if [ $operation == 'ls' ]; then
		echo "[ls result]"
		$operation
	elif [ $operation == 'pwd' ]; then
		echo "[pwd result]"
		$operation
	elif [ $operation == 'add' ]; then
		echo "Enter two number to add:"
		read num1
		read num2
		echo "$num1 + $num2 is `expr $num1 + $num2`"
	elif [ $operation == 'multiply' ]; then
		echo "Enter two number to multiply:"
		read num1
		read num2
		echo "$num1 * $num2 is `expr $num1 \* $num2`"
	elif [ $operation == 'exit' ]; then
		break
	fi
done

