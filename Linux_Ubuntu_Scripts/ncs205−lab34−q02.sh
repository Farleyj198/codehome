#!/bin/sh
# File name: ncs205−lab34−q02.sh
# Author: James Farley
# Date Written: 3/27/2021
5 # Assignment: Lab34
# Purpose: To remove one or mulitple files
# Description: This script will take in file names as a argument to remove them.
 It will ask if you do want to
# remove each file or not before it removes them. If not argument is given, a me
ssage on how to use it will appear.
# This script will also allow to skip the checks by using "−f" as the first argu
ment.
10 #
#
#
# If there is no argument it will display its usage for this script.
if [ $# −eq 0 ]; then
15 echo "For this script to work, you must enter at least one file’s location as an armgument for the files you w
ant
to be removed. This script will ask you to if you want to reomve each file before it removes it. You can skip this check
by entering "−f" as the first argument."
exit 0
fi
20 # this will skip the ceck if "−f" is given.
if [ $1 == "−f" ]; then
for di in $*
do
if [ $"$di" == "−f" ]; then
25 shift
else
rm $"$di"
echo removed $"$di"
shift
30 fi
done
else
# This will ask and remove files that were given to it.
for di in $*; do
35 read −p "Are you sure you want to delete the $"$di" file? (Y/N):" con
if [ $con == Y ]
then
rm $"$di"
echo removed $"$di"
40 elif [ $con == y ]
then
 rm $"$di"
echo removed $"$di"
else
45 echo $"$di" was not removed
fi
done
fi
