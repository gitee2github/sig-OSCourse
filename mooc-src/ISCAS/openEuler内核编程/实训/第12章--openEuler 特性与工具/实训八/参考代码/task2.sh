#!/bin/sh

#挂载resctrl
mount -t resctrl resctrl /sys/fs/resctrl

#准备两个分组,分别对应不同的closid
mkdir -p /sys/fs/resctrl/dataStream_1

#准备运行业务的cpu，0-5跑dataStream_1
echo '0-5' > /sys/fs/resctrl/dataStream_1/cpus_list

#对应cpu上启动业务,注意这些cpu在哪些node上
taskset -c 0-5 -P 4 -W 1 -N 1 -t 1024 > test_2_dataStream_1_1.log

#配置业务流L3Cache
echo 'L3:0=1' > /sys/fs/resctrl/dataStream_1/schemata
taskset -c 0-5 -P 4 -W 1 -N 1 -t 1024 > test_2_dataStream_1_2.log

#配置业务流DDR通道流量
echo 'L3:0=7fff' > /sys/fs/resctrl/dataStream_1/schemata
echo 'MB:0=50' > /sys/fs/resctrl/dataStream_1/schemata
taskset -c 0-5 -P 4 -W 1 -N 1 -t 1024 > test_2_dataStream_1_3.log
