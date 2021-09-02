#!/bin/sh
# File name: ncs205−lab35−q01.sh
# Author: James Farley
# Date Written: 3/27/2021
5 # Assignment: Lab35
# Purpose: The purpose of this script is to multiply two integers togther.
# Description: This script will ask for two integers and then check if they are
integers or not.
# If the are not, they will give out a message that they are not, and end the sc
rpit. If they are integers,
# mulitply them togther. Once that is done, it sends the results to STDOUT.
10 #
#
#
#Taking the first number for the product and putting it into num1.
read −p "Enter a number:" num1
15
#Taking the second number for the product and putting it into num2.
read −p "Enter a second number:" num2
#To see if there are two integers.
20 for count in $num1 $num2; do
test=$num"$count"
check=‘expr $test : ’^[0−9]\{1,\}$’‘
if [ "$check" −eq 0 ]
then
25 echo Enter only integers.
exit 1
fi
done
30 #Multiplying the the two varables stored to get the product.
product=‘expr $num1 \* $num2 2> /dev/null‘
echo The product of the two numbers are: $product
