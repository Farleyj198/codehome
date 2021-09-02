#!/bin/sh
# File name: ncs205−lab36−q02.sh
# Author: James Farley
# Date Written: 3/27/2021
5 # Assignment: Lab36
# Purpose: A Nagios script
# Description: This file will check if it the inuputed argument is real and spec
ified. If the file is not, it will state it and end the script.
# If it goes throught it will let the user know how outdated since the last modi
fcation it was to the file and its status.
#
10 #
#
# checking if the file is existing
if ! [ −f $1 ]; then
15 echo Enter a specified file.
exit 4
fi
# checking if the file is specified
20 if ! [ −e $1 ]; then
echo Enter a real file.
exit 3
fi
25 # Getting the file’s name
file=‘basename $1‘
# Time diffrence ceculator
time2=‘date +"%Y−%m−%d %H:%M:%S"‘
30 time1=‘stat −−format="%y" $1 | awk −F’.’ ’{print $1}’‘
timy1=‘echo $time1 | awk ’{print $1}’ | tr −d ’−’‘
timy2=‘echo $time2 | awk ’{print $1}’ | tr −d ’−’‘
secs1=‘date +%s −d $timy1‘
secs2=‘date +%s −d $timy2‘
35 difftime=‘echo "($secs2 − $secs1)"|bc‘
diffm=‘echo "$difftime / 60"|bc‘
diffh=‘echo "$diffm / 60"|bc‘
diffd=‘echo "$diffh / 24"|bc‘
40 # Critical Check
if [ $diffh −gt 48 ]; then
echo "CRITICAL: $file âM−^@M−^S $time1 ($diffd days)"
exit 2
45 # Warning Check
elif [ $diffh −gt 24 ]; then
echo "WARNING: $file − $time1 ($diffh hours)"
exit 1
50 # Normal Status
else
echo OK: "$file" âM−^@M−^S "$time1"
exit 0
fi
