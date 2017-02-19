#!/bin/bash
echo "Enter your number"
read a
sum=0
while [ $a -gt 0 ]
do
rem=`expr $a % 10`
sum=`expr $sum + $rem`
a=`expr $a / 10`
done
echo $sum
