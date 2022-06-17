#!/bin/bash
s=`cat /proc/$$/cmdline`
echo current process pid is $$
echo current process cmd is $s
s=`cat /proc/$PPID/cmdline`
echo current parent process pid is $PPID
echo current parent process cmd is $s
echo "Do you want to end it?(y or n)"
read input
while [ $input != "y" ]
do
	sleep 1
	read input
done
