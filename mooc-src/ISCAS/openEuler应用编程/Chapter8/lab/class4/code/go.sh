 #!/bin/bash

 # file size
 filesize = 118861

 # file offset
 off = 0

 # number of files
 num = 4

 # fuzz value
 val = 255

 # name counter
 cnt = 0

 while [$cnt - lt $num]
 do
     cp. / iscas.pdf. / iscas_$cnt.pdf
     . / fuzz $filesize $off $val. / iscas_$cnt.pdf
 let "off+=1"
 let "cnt+=1"
 done
