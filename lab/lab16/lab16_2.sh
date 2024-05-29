#!/bin/bash  

getPrimeRange(){
	local min=$1
	if [ $min -eq 1 ];then
		min=2
	fi 
	local max=$2
	local result=()
	local index=0
	until [ $min -ge $max ]; do
		local isprime=1
		local m=2
		until [ $m -gt $((min/2)) ]; do
			if [ $((min%m)) -eq 0 ] ; then
				isprime=0
				break
			fi
			((m++))
		done	
		if [ $isprime -eq 1 ]; then
			result[$index]=$min
			((index++))
		fi
		((min++))
	done
	echo ${result[*]}
}

getRandomPrimeNumber(){
	local Primearray=(`getPrimeRange $1 $2`)
	local index=`expr $RANDOM % ${#Primearray[*]} `
	echo ${Primearray[$index]}
}


coprime() {
	local a=$1
	local b=$2
	if [ $a -eq 0 ] || [ $b -eq 0 ]; then
		echo 0
	elif [ $a -eq $b ]; then 
		echo $a
	elif [ $a -gt $b ]; then
		echo `coprime $((a-b)) $b `
	else
		echo `coprime $a $((b-a))`
	fi
}

getCoprimeRange() {
	local min=$1
	if [ $min -eq 1 ];then
		min=2
	fi 
	local max=$2
	local result=()
	local index=0
	echo `coprime $min $max`
	until [ $min -gt $max ]; do
		if [ `coprime $min $max` = 1 ]; then
			result[index]=$min
			((index++))
		fi
		((min++))
	done
	echo ${result[*]}
}

getCoprimeNumber() {
	local Coprimearray=(`getCoprimeRange $1 $2`)
	local index=`expr $RANDOM % ${#Coprimearray[*]} `
	echo ${Coprimearray[$index]}
}

p=`getRandomPrimeNumber 1 30`
q=`getRandomPrimeNumber 1 30`
n=$((p*q))
m=$(((p-1)*(q-1)))
e=`getCoprimeNumber 1 $m`
echo "p : $p"
echo "q : $q"
echo "n : $n"
echo "m : $m"
echo "e : $e"
