#!/bin/bash

echo "Give a number to check if it is Armstrong number or not : "
read originalNum
div=10000
cubeSum=0
temp=0
tempNum=$originalNum
while [ $div -ne 0 ] ;
do
		temp=$(($tempNum / $div))
		if [ $tempNum -ne 0 ]; then
				cubeSum=$(($(($temp * $temp * $temp)) + $cubeSum))
		    tempNum=$(($tempNum % $div))
		    div=$(($div / 10))
		else
				div=$(($div / 10))
		fi
done
if [ $cubeSum -eq $originalNum ]; then
		echo "The number given $originalNum is Armstrong Number"
else
		echo "The number given $originalNum is not an Armstrong Number"
fi