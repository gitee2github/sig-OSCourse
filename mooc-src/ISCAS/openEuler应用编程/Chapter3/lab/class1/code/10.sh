#!/bin/bash
read file
sort -C $file;
if [ $? -eq 0 ]; then 
	echo "Sorted" ;
else
	echo "Unsorted";
fi
