#!/bin/bash
groupadd class1
i=1
while [ $i -le 30 ]
do
        useradd -G class1 stu${i}
        i=$(($i+1))
done
