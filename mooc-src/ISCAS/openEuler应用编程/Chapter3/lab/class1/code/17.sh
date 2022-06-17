#!/bin/bash
if [ $# -ne 2 ]
then
	echo "$0 match_text filename"
fi
match_text=$1
filename=$2

grep -q $match_text $filename
if [ $? -eq 0 ]
then 
	echo "The text exist in the file"
else
	echo "Text does exist in the file"
fi

