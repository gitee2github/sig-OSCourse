#!/bin/sh
gnome-terminal -t "tty1" -x bash -c "../1/test1;exec bash;"
gnome-terminal -t "tty2" -x bash -c "../1/test1;exec bash;"
gnome-terminal -t "tty3" -x bash -c "../1/test1;exec bash;"
sleep 2
ps aux |grep ../1/test1
sleep 58;
killall test1;
ps aux |grep ../1/test1
