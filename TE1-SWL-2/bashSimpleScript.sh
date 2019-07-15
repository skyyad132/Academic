#!/bin/bash
echo "some text in here"
echo "some other text line in here"
echo "Third line of text in here"

read a b

sum=$(expr $a + $b)

echo "Sum of given two numbers = $sum"

if [ $(expr $a % 2) -eq 0 ]; then
	echo "a given is even"
else
	echo "a is odd"
fi
