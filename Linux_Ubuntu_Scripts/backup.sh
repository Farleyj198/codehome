#!/bin/sh
# File name: backup.sh
# Author: James Farley
# Date Written: 5/8/21
5 # Assignment: Lab 59
# Purpose: To back up the file VM’s server /home filesystem
# Description: This shell script mounts the "/opt/backups/" and crates the /opt/
backups/hostname/ directory if need for both.
# This shell script will then check if an argument is given to it and will check
 diffrent cases to see if what argument or day is correct for it.
# If one is the correct one, it will make a backup and will see if a backup is c
reated.
10
# Mounts the /opt/backups if not alrady mountpoint −q /opt/backups || mount /opt/backups
# Gets the hostname and creates a directory in backups using the hostname.
15 hostname=‘hostname | cut −f2 −d "."‘
mkdir /opt/backups/$hostname > /dev/null 2>&1
# If an argument was given and is not a dobule digit number
# Also will state if the backup was succeful or not.
20 if [ $(expr "$1" : ’^[0−9]\{1,\}$’) −eq 1 ]
then
 level=$1
 xfsdump −F −o −l $level −f /opt/backups/$hostname/home.‘date +%y%m%d‘.$l evel.dump /home | bzip2 > /opt/backups/$hostname/home.‘date +%y%m%d‘.$level.dump
.bz2
 logger −p user.info Backups
25 if [ −e /opt/backups/$hostname/home.‘date +%y%m%d‘.$level.dump.b
z2 ]
then
echo "Home Directory was backed up."
 logger −p user.info Backups
else
30 echo "Home directory was not backed up."
fi
exit 0
# If the date is a Sunday is the first sunday and no argument is given.
35 # Also will state if the backup was succeful or not.
elif [ $(date +%a) = "Sun" ]
then
for i in Sun{01..07}
do
40 if [ $(date +%a%d) = $i ]
then
 level=0
 xfsdump −F −o −l $level −f /opt/backups/$hostname/home.‘date +%y%m%d‘.$l evel.dump /home | bzip2 > /opt/backups/$hostname/home.‘date +%y%m%d‘.$level.dump
.bz2
if [ −e /opt/backups/$hostname/home.‘date +%y%m%d‘.$level.dump.b
z2 ]
45 then
echo "Home Directory was backed up."
 logger −p user.info Backups
else
echo "Home directory was not backed up."
50 fi
echo hi > /dev/null
fi
done
exit 0
55
# If the date is a Sunday but not the fisrt one.
# Also will state if the backup was succeful or not.
elif [ $(date +%a) = "Sun" ]
then
60 level=1
 xfsdump −F −o −l $level −f /opt/backups/$hostname/home.‘date +%y%m%d‘.$l evel.dump /home | bzip2 > /opt/backu$
 logger −p user.info Backups
if [ −e /opt/backups/$hostname/home.‘date +%y%m%d‘.$level.dump.bz2 ]
65 then
echo "Home Directory was backed up."
else
echo "Home directory was not backed up."
fi
70
exit 0
# If a valid level cannot be determined from our argument
# display usage and error out with positive exit status
75 elif
echo Error: Invalid level
echo Usage: $0 [0−9]
# Execute logger here to record this
exit 1
80
else
# If all else fails, it will see it as if this was each remaing day of the week.
# Also will state if the backup was succeful or not.
85 level=2
 xfsdump −F −o −l $level −f /opt/backups/$hostname/home.‘date +%y%m%d‘.$l evel.dump /home | bzip2 > /opt/backu$
 xfsdump −F −o −l $level −f /opt/backups/$hostname/home.‘date +%y%m%d‘.$l evel.dump /home | bzip2 > /opt/backu$
 logger −p user.info Backups
90 if [ −e /opt/backups/$hostname/home.‘date +%y%m%d‘.$level.dump.bz2 ]
then
echo "Home Directory was backed up."
else
echo "Home directory was not backed up."
95 fi
exit 0
fi
