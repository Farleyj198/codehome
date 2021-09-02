# File name: ncs205−lab33−q02.sh
# Author: James Farley
# Date Written: 3/24/2021
# Assignment: Lab 33
5 # Purpose: counting the arguments put into it.
# Description: This script takes in any number of integer arguments and the echo
s out the sum of
# arguments it was given.
#
#
10 #
#¬/bin/sh
#The counter for going through each argument and adding them to the total sum.
while [ $# −gt 0 ]; do
15 sum=‘expr $sum + $1 2> /dev/null‘
shift
done
#Displying the sum of all the initgers inputed to STDOUT.
20 echo Total Sum: $sum
