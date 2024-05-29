#!/bin/bash

func() {
	echo "inside function"
	return 100
}

echo "hello world"
func
echo $?
