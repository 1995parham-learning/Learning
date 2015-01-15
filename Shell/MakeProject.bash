#!/bin/bash
#
# In The Name Of God
# ========================================
# [] File Name : MakeProject.bash
#
# [] Creation Date : 15-01-2015
#
# [] Last Modified : Thu 15 Jan 2015 10:39:12 AM IRST
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

# Use this script to create simple project
# template folder

while [ "$#" -ge "1" ]; do
	mkdir $1
	echo $1 > $1/.gitignore
	vim -c "wq" $1/Makefile
	echo $1 > $1/README.md
	echo "=====" >> $1/README.md
	shift
done
