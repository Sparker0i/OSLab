#!/bin/bash
echo "Enter File Name"
read name
max=0
min=$(head -n 1 $name)
echo $min
while IFS='' read -r line || [[ -n "$line" ]]
do
if [ $line -gt $max ]
then
max=$line
fi
if [ $line -lt $min ]
then
min=$line
fi
done <"$name"
echo "The Minimum value is $min"
echo "The Maximum value is $max"
