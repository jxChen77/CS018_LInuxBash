#!/bin/bash

select operation in $@; do
	case $operation in 
		'ls') echo "[ls result]"
			$operation;;
		'pwd') echo "[pwd result]"
			$operation;;
		'add') echo "Enter two number to add:"
			read num1
			read num2
			echo "$num1 + $num2 is `expr $num1 + $num2`";;
		'multiply') echo "Enter two number to multiply:"
			read num1
			read num2
			echo "$num1 * $num2 is `expr $num1 \* $num2`";;
		'exit') break;;
	esac
done

