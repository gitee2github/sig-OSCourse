#!/bin/bash

mypath=$(echo $PATH|sed 's/:/ /g')
totalcnt=0
cnt=0

for  dir in $mypath

do
        lst=$(ls $dir)
        cnt=0
        for item in $lst
        do
                cnt=$(($cnt+1))
        done
        echo "$dir : $cnt"
        totalcnt=$(($totalcnt+$cnt))
done
echo $totalcnt
