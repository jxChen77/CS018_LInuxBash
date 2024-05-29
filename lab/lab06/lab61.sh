if [[ ! $# = 3 ]]; then
	echo "You should provide three strings"
else 
	max=$1
	med=$1
	min=$1
	for i in $@
	do
		if [[ $i <  $min ]]; then
			if [[ $min != $1 ]]; then
				med=$min
			fi
		       min=$i
	       elif [[ $i > $max ]] ; then
		       if  [[ $max != $1 ]]; then
			       med=$max
		       fi
			max=$i
	 	else
			med=$i
		fi
	done
	echo "$min < $med < $max"
fi
