#!/bin/bash
re(){
	num=1
	re2(){
		if [ $num -lt 2 ];then
			(( num++ ))
			echo $num
			echo "re"
			re
		fi
	}
	return re2()
}

re
