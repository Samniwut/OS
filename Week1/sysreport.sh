#!/bin/bash

#sysreport.sh - collect system information for Lab 1 (Ubuntu 24.04) 
echo "===== OS =====" 
grep PRETTY_NAME /etc/os-release 
uname -srm 
echo "===== CPU =====" 
lscpu | grep -E 'Model name|^CPU\(s\)|Thread|Core' 
echo "===== Memory =====" 
free -h 
echo "===== Disk =====" 
df -h / | tail -n 1 
echo "===== Uptime / Load =====" 
uptime 
echo "===== Processes =====" 
echo "total processes: $(ps -e --no-headers | wc -l)" 
