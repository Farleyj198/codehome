# File name: ncs205−lab33−q05.sh
# Author: James Farley
# Date Written: 3/24/2021
# Assignment: Lab33https://github.com/Farleyj198/codehome
5 # Purpose: The purpose of this script is to remove each ordinary file with a siz
e of zero in a
# directory.
# Description: This script checks if there is a argument or not. If there is no
argument,
# the directory with the script will be the chosen directory for the script. If
there is an argument,
# that will be the chosen directoy. Once the directoy is chosen, it will check i
f it realy is a
10 # directory or not. If it is not, it will display that it is not one and end the
 script, and if it is,
# the script will sort through the files in it until it finds all files with a s
ize of 0 and then
# removes all of them.
#
#
15 #
#¬/bin/sh
# If there is no argument it will remove all ordinary files with a size 0 in the
 scripts directory.
if [ $# −ne 1 ]
20 then
removal=‘ls −l | awk ’{print $1,$5,$9}’ | grep ^− | awk ’{print $2,$3}’ | grep ^0 | awk ’
{print $2}’‘
rm $removal 2> /dev/null
echo Removed: $removal
exit 0
25
# If the argument is not a directory, it will display a message that states it a
nd exits the script.
elif [ ¬ −d $1 ]
then
echo $1 is not a directory.
30 exit 1
fi
# This removes all ordinary files with a size 0 in the directoy specified in the
 argument.
dir=$1
35 cd $dir
removal=‘ls −l | awk ’{print $1,$5,$9}’ | grep ^− | awk ’{print $2,$3}’ | grep ^0 | awk ’
{print $2}’‘
rm $removal 2> /dev/null
echo Removed: $removal
exit 0
