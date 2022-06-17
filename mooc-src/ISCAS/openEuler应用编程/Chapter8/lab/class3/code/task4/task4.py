#!/usr/bin/python

def read_xml():
	try:
		myfile = open('my.text',"r")
		key = [ line.split()[2] for line in myfile.readlines() if len(line.strip()) ]
		dict_key = dict([[k,key.count(k)] for k in set(key)])

		print dict_key

		myfile.close()
	except:
		pass

if __name__ == "__main__":
	read_xml()
