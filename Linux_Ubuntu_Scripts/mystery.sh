#!/bin/sh
# File name: mystery.sh
# Date Written: A long time ago
# Purpose: Mystery script
# Description: This script checks if the argument inputed is an directory or not. If their is no 
# argument or more than one argument, it will give directory of this script and a exit status 1.
# If the argument is not a directory, it will state so and give a exit status 2. If one argument
# was inputed with this script and is a directory, it will list the directory location in the 
# shell and its contents with an exit status 0.
#
#
#
#
if [ $# -ne 1 ]
then
echo Usage: $0 DIRECTORY
exit 1
elif [ ! -d $1 ]
then
echo $1 is not a directory
exit 2
fi
dir=$1
cd $dir
files=*
echo $dir
echo $files
exit 0
