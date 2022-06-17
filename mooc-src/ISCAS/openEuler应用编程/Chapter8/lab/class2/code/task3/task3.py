#!/usr/bin/python
# -*- coding : utf-8 -*-
import sys
import hashlib
import task1
import task2
def getMD5(patch, source) :
	lenp = len(patch)//算出patch的长度
	lens = len(source)//算出source的长度
	md5p = hashlib.md5(''.join(patch)).hexdigest()//将patch所有的字符串连接起来后，用md5算出摘要
	md5s = [hashlib.md5(''.join(source[i:i+lenp])).hexdigest() for i in range(0,lens-lenp)]//用循环切分做source的摘要
	print md5p
	print md5s
	if md5p in md5s ://判断md5p是否存在md5s中
		print "OK"
	return md5s, md5p

if __name__ == "__main__" :
	if(len(sys.argv) != 3) :
		print("usage: %s patchfile sourcefile"%(sys.argv[0]))
		sys.exit()
	patch = task1.doit(sys.argv[1])
	source = task2.doit(sys.argv[2])
	getMD5(patch, source)
