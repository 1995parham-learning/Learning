#!/bin/bash
set -e

echo 'download dvd rental database sample'

wget https://www.postgresqltutorial.com/wp-content/uploads/2019/05/dvdrental.zip
unzip dvdrental.zip
rm dvdrental.zip
