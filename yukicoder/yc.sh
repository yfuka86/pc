#!/bin/bash
mkdir $1
cd $1

for p in $(seq $2 $3)
do
  mkdir ${p}
  cp ~/work/pc/temp/mainyf.cpp ./${p}/${p}.cpp
  cd ${p}
  oj d "https://yukicoder.me/problems/no/${p}"
  cd ..
done

exit 0
