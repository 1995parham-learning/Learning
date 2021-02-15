#!/bin/bash
# In The Name of God
# ========================================
# [] File Name : go.sh
#
# [] Creation Date : 15-02-2021
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================

cd ./go

for prj in */; do
        echo $prj && cd $prj
        golangci-lint run
        cd ..
done
