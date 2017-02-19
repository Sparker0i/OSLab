#!/bin/bash
echo "Enter Number"
read num
for i in 1 2 3 4 5 6 7 8 9 10
do
mul=`expr $i \* $num`
echo "$num x $i = $mul"
done

