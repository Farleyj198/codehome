#!/bin/sh
# File name: ncs205−lab34−q03.sh
# Author: James Farley
# Date Written: 3/27/2021
5 # Assignment: Lab34
# Purpose: Displays user information
# Description: This script will take in an argument of a user to show informatio
n of that user. It will check if their is a argument or if the user is real.
# if either are not the case, it will give back an messege and end the script. I
f both are true, it will provide the users login name, real name, UID,
# home direcotry and finaly login.
10 #
#
#
#Checking if an argument has been implented
15 if [ $# −lt 1 ]
then
echo An argument must be entered for this string to work.
exit 1
fi
20
#Checking if the user is real
user=‘awk −F’:’ ’{ print $1}’ /etc/passwd | grep $1‘
if [ $user != $1 ]
then
25 echo Enter a real username.
exit 2
fi
#displaying the information of the user.
30 echo Login name: ‘finger $1 | head −n 1 | awk ’{print $2}’ | grep −v /‘
echo Name: ‘finger $1 | head −n 1 | awk ’{print $4,$5}’ | grep −v /‘
echo UID: ‘id $1 | awk ’{print $1}’ | tr −d [:alpha:] | tr [:punct:] ’ ’ | awk ’{pri
nt $1}’‘
echo Home directory: ‘finger $1 | awk ’/:/ {print $2}’ | grep /‘
echo Last Login: ‘last $1 | head −n 1| awk ’{print $4,$5,$6,$7}’‘
