#!/bin/bash
a=”/var/log/boot.log”
echo ${a%/*}		#/var/log
echo ${a##*/}		#boot.log
echo ${a##*.} 	#log
