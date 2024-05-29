#!/bin/bash

function step2() {
	echo "step 2"
	return
}

function step3 {
	echo "step 3"
	return 
}

step4() {
	echo "step 4"
	return 
}

mytest1() {
	echo $var
}

mytest2() {
	var="foo"
	echo $var
}

mytest3() {
	local var="local"
	echo $var
}

echo step1
step2
step3
step4
var="hello"
mytest1
mytest2
mytest3
echo $var
mytest1
