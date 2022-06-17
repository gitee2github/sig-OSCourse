#!/bin/bash
for line in $(cat testfile)
do
        echo $line | tr a-z A-Z        
done
