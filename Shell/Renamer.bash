#!/bin/bash
#
# In The Name Of God
# ========================================
# [] File Name : Renamer.bash
#
# [] Creation Date : 15-01-2015
#
# [] Last Modified : Thu 15 Jan 2015 10:39:05 AM IRST
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
shopt -s nullglob
a=1
for i in *.jpg; do
	new=$(printf "%d.jpg" ${a})
	mv "${i}" "${new}"
	let a=a+1
done
for i in *.JPG; do
	new=$(printf "%d.jpg" ${a})
	mv "${i}" "${new}"
	let a=a+1
done
shopt -u nullglob
