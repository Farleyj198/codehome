# File name: ncs205−lab33−q03.sh
# Author: James Farley
# Date Written: 3/24/2021
# Assignment: Lab33
5 # Purpose: The purpose of this script is to add two integers togther.
# Description: This script will see if there are two arguments and give back a m
essage if it is not.
# If it has two arguments that are integers, it will take the two integers argum
ents and add them
# togther. Once that is done, it sends the results to STDOUT.
#
10 #
#
#¬/bin/sh
#To see if there are two arguments.
15 if [ $# −ne 2 ]
then
echo Only two argumnets
exit 11
fi
20
#Add the two arguments togther to get their sum.
sum=‘expr $1 + $2 2> /dev/null‘
#Displaying the sum to STDOUT.
25 echo The sum of the two intgers are: $sum
