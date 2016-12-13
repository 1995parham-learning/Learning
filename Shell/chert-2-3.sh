#!/bin/bash
# In The Name Of God
# ========================================
# [] File Name : chert-2-3.sh
#
# [] Creation Date : 07-12-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
i=0
for f in `ls /bin/*z*`; do
	echo $f
	i=$(($i + 1))
done
echo $i
