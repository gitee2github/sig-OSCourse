#/bin/bash
read -p "input a file:" filename
if [ -b $filename -o -c $filename ]
#echo $filename is not char device and not block device
then
	cp $filename /dev/
	
fi
