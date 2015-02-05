#!/bin/bash
#
# In The Name Of God
# ========================================
# [] File Name : MakeProject.bash
#
# [] Creation Date : 15-01-2015
#
# [] Last Modified : Fri 06 Feb 2015 01:28:04 AM IRST
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

# Use this script to create simple project
# template folder

if [ "$#" -eq "0" ]; then
	echo "Usage: $0 Poject Name"
fi

# Use -fc for fast C project...
arg_fc=0
# Use -fs for fast Assembly project...
arg_fs=0

# If set to 0 the Makefile with template
# created for your project else empty
# makefile created.
template_makefile=0

while [ "$#" -ge "1" ]; do
	if [ "$1" = "-fc" ]; then
		arg_fc=1
		shift
		continue
	fi

	if [ "$1" = "-fs" ]; then
		arg_fs=1
		shift
		continue
	fi

	if [ -d $1 ]; then
		echo "Folder $1 exist.."
		shift
		continue
	fi

	# Default operations
	mkdir $1
	echo "$1" > $1/.gitignore
	if [ "$template_makefile" -eq "0" ]; then
		vim -c "wq" $1/Makefile
	else
		touch $1/Makefile
	fi
	echo "$1" > $1/README.md
	echo "=====" >> $1/README.md

	# Fast C project
	if [ "$arg_fc" -eq "1" ]; then
		vim -c "wq" $1/$1.c
		vim -E -c "%s/P=/P=$1" -c "wq" $1/Makefile
		vim -E -c "%s/OBJ=/OBJ=$1.o" -c "wq" $1/Makefile
	fi

	# Fast Assembly project
	if [ "$arg_fs" -eq "1" ]; then
		vim -c "wq" $1/$1.S
		vim -E -c "%s/P=/P=$1" -c "wq" $1/Makefile
		vim -E -c "%s/OBJ=/OBJ=$1.o" -c "wq" $1/Makefile
	fi

	shift
done
