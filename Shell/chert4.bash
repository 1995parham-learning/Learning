#!/bin/bash
# In The Name Of God
# ========================================
# [] File Name : chert4.bash
#
# [] Creation Date : 08-03-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
counter=0
for dir in `ls /bin --sort=time --time=atime`; do
	let counter=$counter+1
	echo "$counter: $dir"
	if [ $counter -eq 10 ]; then
		exit
	fi
done
