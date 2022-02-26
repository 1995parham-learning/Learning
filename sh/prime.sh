#!/bin/bash
# In The Name Of God
# ========================================
# [] File Name : prime.sh
#
# [] Creation Date : 28-12-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

is_prime() {
	n=$1
	count=0

	for i in $(seq 1 "$n"); do
		if [ $((n % i)) -eq 0 ]; then
			count=$((count + 1))
		fi
	done

	if [ $count -eq 2 ]; then
		return 0
	fi

	return 1
}

if [ "$(is_prime "$1")" -eq 0 ]; then
	echo "Prime"
else
	echo "Not Prime"
fi
