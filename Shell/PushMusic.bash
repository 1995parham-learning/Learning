#!/bin/bash
#
# In The Name Of God
# ========================================
# [] File Name : PushMusic.bash
#
# [] Creation Date : 15-01-2015
#
# [] Last Modified : Mon 23 Mar 2015 12:48:34 PM IRDT
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

# Use this script inorder to push musics
# from current with rsync into
# user home folder music

# Use sim for simulation
sim=0

RED=`echo -e '\033[41m\033[37m'`
NORMAL=`echo -e '\033[0m'`

if [ "$1" = "sim" ]; then
	sim=1
fi

if [ "$sim" -eq 0 ]; then
	# Default mode
	rsync -trvuih . $USER@localhost:$HOME/Music \
		 | sed -e "s/^<.*$/$RED&$NORMAL/"
else
	# Simulation mode
	rsync -trvuihn . $USER@localhost:$HOME/Music \
		 | sed -e "s/^<.*$/$RED&$NORMAL/"
fi
