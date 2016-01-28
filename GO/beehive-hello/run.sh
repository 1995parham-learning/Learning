#!/bin/bash
# In The Name Of God
# ========================================
# [] File Name : run.sh
#
# [] Creation Date : 19-11-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
if [ -d /tmp/beehive ]; then
	echo "Remove beehive states.. :)"
	rm -Rf /tmp/beehive
fi

echo "Run beehive-hello :)"
go run beehive-hello.go
