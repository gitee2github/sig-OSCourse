#!/usr//bin/python
import sys

def doit( patch_path ) ://定义一个函数，并且给一个变量，用来处理传进来的diff文件
	#print(patch_path)//打印传进来的文件名
	patch_filename = patch_path.split('/')[-1]//先以/为分隔符，将patch_path分割出来，再取倒数第一个字符串为文件名
	#print(patch_filename)//打印文件名
	patch_file = open(patch_path, "r")//以只读的方式打开所要处理的文件，并返回文件描述符patch_file
	patch_lines = patch_file.readlines()//一行一行取文件到patch_lines当中, 调用readline()可以每次读取一行内容，调用readlines()一次读取所有内容并按行返回list。
	patch_file.close()//关闭文件描述符
	patch_feature = []//定义一个列表patch_feature
	for line in patch_lines ://循环的对遇到的情况做处理
		if line.startswith("+++") or line.startswith("---") ://以+++和---开头的忽略
			pass//相当一个占位符
		elif line.startswith("+") ://+好开头的也忽略
			pass
		elif line.startswith(" ") or line.startswith("-") :保留-号开头和既没有-号也没有+号
			line = line[1:].strip()//去掉第1行以后的开头和结尾的空白符
			if line ://不为空
			#	print line
				line = "".join(line.split())//line.split()//相当于就是line本身，将join括号中的字符串以join前面的引号中的分割符连接起来，split（）里面的默认为空格。
			#	print line
				patch_feature.append(line.lower())//将字符传转化为小写之后，添加到patch_fature列表的后面。
	print patch_feature
	return patch_feature


if( __name__ == "__main__" ):
	mylen = len(sys.argv)
	if( mylen != 2 ) :
		print("Usage: "+sys.argv[0]+" patch_path")
		exit(1)
	else :
		doit(sys.argv[1])	
