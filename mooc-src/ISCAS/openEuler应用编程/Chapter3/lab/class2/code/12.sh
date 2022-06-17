#!/bin/bash
i=1
while [ i –le 50 ]
do
$(sudo mkdir -p /userdata/user$i)
chmod 754 /userdata/user$i
i=$(($i+1)
done
