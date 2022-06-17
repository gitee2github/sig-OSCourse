#!/bin/bash
cat filename(待读取的文件) | while read line
do
    echo $line
done
