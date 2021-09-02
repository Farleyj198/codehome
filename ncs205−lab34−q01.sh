#!/bin/sh
# File name: ncs205−lab34−q01.sh
# Author: James Farley
# Date Written: 3/27/2021
5 # Assignment: Lab34
# Purpose: To remove one or mulitple files
# Description: This script will take in file names as a argument to remove them.
 It will ask if you do want to
# remove each file or not before it removes them. If not argument is given, a me
ssage on how to use it will appear.
#
10 #
#
# If there is no argument it will display its usage for this script.
if [ $# −eq 0 ]; then
echo "For this script to work, you must enter at least one file’s location as an armgument for the files you
 want
15 to be removed. This script will ask you to if you want to reomve each file before it removes it."
exit 0
fi
# This will ask and remove files that were given to it.
20 for di in $*
do
read −p "Are you sure you want to delete the $"$di" file? (Y/N):" con
if [ $con == Y ]
then
25 rm $"$di"
echo removed $"$di"
elif [ $con == y ]
then
 rm $"$di"
30 echo removed $"$di"
else
echo $"$di" was not removed
fi
done
