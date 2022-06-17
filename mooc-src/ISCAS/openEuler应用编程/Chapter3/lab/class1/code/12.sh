#!/bin/bash
while :
do
	echo "Please input file's name"
	read a
	if test -e $a
	then
		echo "the file is existing Please input a new file"
	else
		mkdir $a
		echo "you are sussesful!"
		break
	fi
done
