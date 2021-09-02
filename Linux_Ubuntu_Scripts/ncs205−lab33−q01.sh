# File name: ncs205−lab33−q01.sh
# Author: James Farley
# Date Written: 3/24/2021
# Assignment: Lab33
5 # Purpose: To echo out your first nine arguments
# Description: This script takes in the first 9 arguments given and echos them o
ut.
#
#
#
10 #¬/bin/sh
#This command is taking the first nine arguments and capitalizing and displaying
 them to STDOUT.
echo 1st Argument: $1 | tr [:lower:] [:upper:]
15
echo 2nd Argument: $2 | tr [:lower:] [:upper:]
echo 3rd Argument: $3 | tr [:lower:] [:upper:]
20 echo 4th Argument: $4 | tr [:lower:] [:upper:]
echo 5th Argument: $5 | tr [:lower:] [:upper:]
echo 6th Argument: $6 | tr [:lower:] [:upper:]
25
echo 7th Argument: $7 | tr [:lower:] [:upper:]
echo 8th Argument: $8 | tr [:lower:] [:upper:]
30 echo 9th Argument: $9 | tr [:lower:] [:upper:]
