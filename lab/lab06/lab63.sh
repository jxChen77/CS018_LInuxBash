echo -n "Enter a command: "
read com
echo ""
case $com in
	date)
		echo "[Today's date]"
		date;;
	pwd)
		echo "[Here is a present working directory]"
		pwd;;
	ls)
		echo "[Here is a list of files]"
		ls;;
	gcc)
		echo "[Enter filename to compile and execute]"
		read filename
		gcc -o "te" $filename
		./"te"
		rm "te";;
	*)
		echo "Enter date, ls, pwd, or gcc";;
	esac
