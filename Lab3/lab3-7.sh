#!/bin/bash
echo "Enter Starting Number"
read a
echo "Enter Second Number"
read b
echo "Odd Numbers are...."
while [ $a -le $b ]
do
cond=`expr $a % 2`
if [ $cond -ne 0 ]
then
echo $a
fi
a=`expr $a + 1`
done
