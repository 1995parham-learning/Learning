#!/bin/bash

shopt -s extglob
ls /dev/sd+([[:lower:]])
if [ "$UID" -eq "0" ]; then
	for disk in /dev/sd+([[:lower:]]); do
		fdisk -l $disk
	done
fi
