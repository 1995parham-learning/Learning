#!/bin/bash
# In The Name Of God
# ========================================
# [] File Name : prime.sh
#
# [] Creation Date : 28-12-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
a=$1

answer=0

for i in `seq 1 $a`; do
	if [ $(($a % $i)) -eq 0 ]; then
		answer=$(($answer + 1))
	fi
done

if [ $answer -eq 2 ]; then
	echo "Prime"
else
	echo "Not Prime"
fi
