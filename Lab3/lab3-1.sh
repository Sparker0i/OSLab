#!/bin/bash
echo "Enter Number to Search For"
read a
echo "Enter File Name"
read b
grep $a $b
