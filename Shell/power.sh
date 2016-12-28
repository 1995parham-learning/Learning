#!/bin/bash
# In The Name Of God
# ========================================
# [] File Name : power.sh
#
# [] Creation Date : 28-12-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
a=$1
b=$2

answer='1'

for i in `seq 1 $b`; do
	answer=$(($a * $answer))
done

echo $answer
