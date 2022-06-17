#!bin/bash
#cat ~/.bash_history | sort | uniq -c | sort -nr | head -n5
cat ~/.bash_history |sed 's/|/\n/g'|awk '{print $1}'|sort |uniq -c|sort -nr -k1|head -n 5

