echo -n "Enter n : "
read lines
i=0
while (( i < lines )) ; do
	j=0
	while (( j <= i )); do
		echo -n "* "
		(( j++ ))
	done
	echo ""
	(( i++ ))
done

