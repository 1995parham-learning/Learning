#!/bin/bash

mkdir $1
vim $1/$1.asm -c "wq"
cp Makefile $1
