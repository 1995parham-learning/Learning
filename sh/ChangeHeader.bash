#!/bin/bash
#
# In The Name Of God
# ========================================
# [] File Name : ChangeHeader.bash
#
# [] Creation Date : 20-01-2015
#
# [] Last Modified : Tue 20 Jan 2015 08:20:42 AM IRST
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

while [ "$#" -ge "1" ]; do
	cp $1 $1.bak
	tail -n +11 $1 > $1.new.1
	rm $1
	vim $1 -c "wq"
	cat $1 $1.new.1 > $1.new.2
	rm $1.new.1
	mv $1.new.2 $1
	shift
done
