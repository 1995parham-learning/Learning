#/bin/bash

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
