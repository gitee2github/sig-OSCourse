#!/bin/bash
#!/bin/bash
i=1  
while [ $i -le 30 ] 
do  
userdel -r stu${i}
i=(($i+1 )) 
done 
groupdel class1
