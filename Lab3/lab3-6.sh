#!/bin/bash
echo "Enter a Number"
read a
start=1
fact=1
while [ $start -le $a ]
do
fact=`expr $fact \* $start`
start=`expr $start + 1`
done
echo $fact
