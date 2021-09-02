# File name: ncs205−lab33−q04.sh
# Author: James Farley
# Date Written: 3/24/2021
# Assignment: Lab33
5 # Purpose: The purpose of this script is to add two integers togther.
# Description: This script will ask for two integers and add them togther. Once
that is done,
# it sends the results to STDOUT.
#
#
10 #
#¬/bin/sh
#Taking the first number for the sum and putting it into num1.
read −p "Enter a number:" num1
15
#Taking the second number for the sum and putting it into num2.
read −p "Enter a second number:" num2
#Adding the the two varables stored to get the sum.
20 sum=‘expr $num1 + $num2 2> /dev/null‘
#Displaying the sum to STDOUT.
echo The sum of the two numbers are: $sum
