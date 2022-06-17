#!/bin/sh

#挂载resctrl
mount -t resctrl resctrl /sys/fs/resctrl

#准备两个分组,分别对应不同的closid
mkdir -p /sys/fs/resctrl/dataStream_1
mkdir -p /sys/fs/resctrl/dataStream_2

#准备运行业务的cpu，0-5跑dataStream_1，6-10跑dataStream_2
#这一步即为对两组cpu关联不同的closid
echo '0-5' > /sys/fs/resctrl/dataStream_1/cpus_list
echo '6-10' > /sys/fs/resctrl/dataStream_1/cpus_list

#对应cpu上启动业务,注意这些cpu在哪些node上
taskset -c 0-5 lmbench/bw_mem -P 5 -N 100 512M rd > /dev/null 2>&1 &
taskset -c 6-10 lmbench/bw_mem -P 5 -N 100 1024M rd > /dev/null 2>&1 &

#第一轮读取monitor的值，每轮读10次
for var in {1..10}
do
	grep . /sys/fs/resctrl/dataStream_1/mon_data/* >> test_1_dataStream_1_1.log
	grep . /sys/fs/resctrl/dataStream_2/mon_data/* >> test_1_dataStream_2_1.log
	sleep 1
done

#配置业务流
echo 'L3:0=ff' > /sys/fs/resctrl/dataStream_1/schemata
echo 'MB:0=2' > /sys/fs/resctrl/dataStream_1/schemata
echo 'L3:0=7f00' > /sys/fs/resctrl/dataStream_2/schemata
echo 'MB:0=10' > /sys/fs/resctrl/dataStream_2/schemata

#第二轮读取monitor的值，每轮读10次
for var in {1..10}
do
	grep . /sys/fs/resctrl/dataStream_1/mon_data/* >> test_1_dataStream_1_2.log
	grep . /sys/fs/resctrl/dataStream_2/mon_data/* >> test_1_dataStream_2_2.log
	sleep 1
done
