#!/bin/bash
#wget -P ~/myDownloads http://img2.3lian.com/img2007/19/26/030.jpg 
i=1
wget -b  -P ~/myDownloads -i filelist.txt

for filename in `ls -l ~/myDownloads|awk '{print $9}'`
do
   mv "$filename"  doc$i.jpg
   ((i++))
done
