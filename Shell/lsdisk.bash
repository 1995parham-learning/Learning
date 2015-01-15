#!/bin/bash
#
# In The Name Of God
# ========================================
# [] File Name : lsdisk.bash
#
# [] Creation Date : 15-01-2015
#
# [] Last Modified : Thu 15 Jan 2015 10:36:33 AM IRST
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

shopt -s extglob
ls /dev/sd+([[:lower:]])
if [ "$UID" -eq "0" ]; then
	for disk in /dev/sd+([[:lower:]]); do
		fdisk -l $disk
	done
fi
