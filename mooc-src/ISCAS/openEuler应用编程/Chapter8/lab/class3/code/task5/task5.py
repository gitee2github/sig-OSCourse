import pylab
import numpy as np

if __name__=="__main__":
    try:
        myfile = open("./test.txt","r")
        key = [line.split()[2] for line in myfile.readlines() if len(line.strip())]        
	dict_key = dict([[k,key.count(k)] for k in set(key)])
        print dict_key
        myfile.close()
    except:
        pass

    wordlist=[]
    for k,v in dict_key.iteritems():
        wordlist.append((k,v))
    keylist=[k for k,v in wordlist]
    vallist=[v for k,v in wordlist]
    barwidth = 0.5
    xVal = np.arange(len(keylist))
    pylab.xticks(xVal+barwidth/2.0,keylist,rotation=45)
    pylab.bar(xVal,vallist,width=barwidth,color='y')
    pylab.title(u'data analysis')
    pylab.show()	

