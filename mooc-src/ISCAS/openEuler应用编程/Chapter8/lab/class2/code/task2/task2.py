#!/usr/bin/python
# -*- coding : utf-8 -*-
import sys
import common 
def doit(file_path) :
	filefd = open(file_path, "r")//以只读的方式打开文件传进来的文件，返回文件描述符filefd
	filewr = open("myfile","w")//以只写的方式打开文件myfile，返回文件描述符filewr
	filewr2 = open("myfile2","w")//以只写的方式打开文件myfile2，返回文件描述符filewr2
	file_line = filefd.read()//将传进来的文件file_path,全部读到file_line变量（str对象）中
	filefd.close()//关闭文件描述符
	mylines = []//定义一个list对象
	for line in common.c_regex.finditer(file_line) ://调用common模块当中的c_regex对象的finditer方法，返回迭代器，对于每个匹配，返回一个匹配对象的列表。
		if line.group("noncomment")://返回所有匹配对象或是根据要求返回某个特定子组
			mylines.append(line.group("noncomment"))
	norm_line = "".join(mylines)//将列表中的所有元素连接起来
	norm_line = norm_line.lower()//将norm_line的所有的字符串都转化为小写
	norm = norm_line.split("\n")//将norm_line的字符串以\n为分隔符切分成一行一行的
	mynorm = ["".join(item.strip().split(" "))  for item in norm if item.strip()]//最前面的那句话是一次循环，满足if语句为真时，执行的语句，item.strip()表示删除item开头和结尾处的空白符，item.strip().split(" ")表示以空格为分隔符分割item,for循环就是达到一行一行的处理。
	print mynorm//打印mynorm
	return mynorm//返回mynorm

if ( __name__ == "__main__" ) ://确定该文件是模块还是，执行文件，如果返回true，则不是模块，继续执行。
	if(len(sys.argv) != 2) ://判断传入的参数不小于2
		print("Usage : %s filepath"%(sys.argv[0]))//打印调用该执行该脚本的正确方法
		sys.exit()//退出
	doit(sys.argv[1])//调用前面定义的函数
