#!/bin/bash
i=1
echo "input a num"
read n;
m=1
while [ i -le n ];
do
	((m=m*i))
	((i=i+1))
done
echo $m
