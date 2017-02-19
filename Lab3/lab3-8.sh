#!/bin/bash
echo "Enter Length of Rectangle"
read length
echo "Enter Breadth of Rectangle"
read breadth
echo "Enter Radius"
read radius
pi=`expr 22 / 7`
echo "calculating......"
peri=`expr $length + $breadth`
peri=`expr 2 \* $peri`
arear=`expr $length \* $breadth`
carea=`expr $pi \* $radius \* $radius`
circum=`expr 2 \* $pi \* $radius`
echo "Area of Rectangle is $arear and Perimeter is $peri"
echo "Area of Circle is $carea and Circumference is $circum"
