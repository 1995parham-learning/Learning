#!/bin/bash
set -e

if [ -f dvdrental.tar ]; then
	exit
fi
echo 'download dvd rental database sample'

wget https://www.postgresqltutorial.com/wp-content/uploads/2019/05/dvdrental.zip
unzip dvdrental.zip
rm dvdrental.zip
