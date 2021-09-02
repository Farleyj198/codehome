#!/bin/sh
# File name: ncs205−lab34−q04.sh
# Author: James Farley
# Date Written: 3/27/2021
5 # Assignment: Lab34
# Purpose: To make backups of a file
# Description: This script first creates a backup spot for your backup files if
you do not alraedy have one.
# This script then will make a copy of the file given by an argument and will se
nd it too the the ~/backups/
# drectory. It will rename the copy to its basename plus its date and time it wa
s copied.
10 #
#
#
#Checking if "~backups/" is a location or not and making it one if not.
15 if [ −d ~/backups/ ]; then
echo "backups is already made"
else
mkdir ~/backups/
echo "backups is now made"
20 fi
# Taking the base name of the file and placing it in the varable called "file".
file=‘basename $1‘
25 # Making a copy of the file to ~/backups/ and the copies name is its basename pl
us the date it was coppied.
cp $1 ~/backups/"$file"−‘date +"%y%m%d:%H%M"‘
