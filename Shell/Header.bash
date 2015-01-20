#!/bin/bash
#
# In The Name Of God
# ========================================
# [] File Name : Header.bash
#
# [] Creation Date : 20-01-2015
#
# [] Last Modified : Tue 20 Jan 2015 08:21:12 AM IRST
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

while [ "$#" -ge "1" ]; do
	mv $1 $1.bak
	vim $1 -c "wq"
	cat $1 $1.bak > $1.new
	mv $1.new $1
	shift
done
