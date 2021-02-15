#!/bin/bash
# In The Name of God
# ========================================
# [] File Name : rush.sh
#
# [] Creation Date : 15-02-2021
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================

cd rust
for prj in */; do
  echo $prj && cd $prj
  cargo fmt
  cargo clippy --all-targets --all-features -- -D warnings
  cd ..
done
