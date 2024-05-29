#!/bin/bash

num=$2
inFile=$3
outFile=$4
upper=`echo {A..Z} {A..Z} | tr -d " "`
lower=`echo {a..z} {a..z} | tr -d " "`
enUpper=`echo ${upper:$num:26}`
enLower=`echo ${lower:$num:26}`
deUpper=`echo ${upper:$((26-$num)):26} | tr -d " "`
deLower=`echo ${lower:$((26-$num)):26} | tr -d " "`
newDe=$deLower$deUpper
newEn=$enLower$enUpper
if [ $1 = "d" ]; then
	cat $inFile | tr 'a-zA-Z' "$newDe" > $outFile
fi

if [ $1 = "e" ]; then
	cat $inFile | tr 'a-zA-Z' "$newEn" > $outFile

fi


