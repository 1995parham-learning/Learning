#!/bin/bash
# In The Name Of God
# ========================================
# [] File Name : power.sh
#
# [] Creation Date : 28-12-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

power() {
	a=$1
	b=$2
	answer='1'

	for i in `seq 1 $b`; do
		answer=$(($a * $answer))
	done

	echo $answer
}

# Main script (!) Let's test our power function
echo `power 2 4`
echo `power 4 2`
echo `power 3 4`
