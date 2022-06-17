#!/usr/bin/python
// xml.etree.ElementTree模块实现了一个简单而有效的用户解析和创建XML数据
//的API。
from xml.etree import ElementTree
import string

def read_xml(text):
	root = ElementTree.parse(text)//解析xml文件，获得root节点
	lst_node = root.getiterator("error")//获得树中的error节点,返回的是所有//的error节点的一个列表
	f = open("my.text","w")//打开文件
	for node in lst_node://循环去error节点中找出信息
		_id = node.attrib['id']//取出id值
		severity = node.attrib['severity']//取出servrity值
		msg = node.attrib['msg']//取出msg值
		verbose = node.attrib['verbose']//取出verbose值
		sub_node = node.find('location')//找到location位置的值，指出了具体//的哪个文件的哪一行出现了error
		try:
			cfile = sub_node.attrib['file']//取出file的起始位置
			line = sub_node.attrib['line']//定位到出现error的具体的行号
			file_line = cfile+":"+line//定义到行号
		except:
			pass
		content = file_line + " " + _id + " " + severity + " " + msg + "\n\n " #+ verbose + " " + cfile + " " + line + "\n\n"
		print content

		f.write(content)
	f.close()

if __name__ == "__main__":
	read_xml('err.text')

