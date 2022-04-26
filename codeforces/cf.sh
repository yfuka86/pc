#!/bin/bash
if [ $# -ne 2 ]; then
  echo "Must specify contest id and number of problems by alphabet" 1>&2
  exit 1
fi

mkdir $1
cd $1

for p in $(eval echo {a..$2});
do
  mkdir ${p}
  cp ~/work/pc/temp/maincf.cpp ./${p}/${p}.cpp
done

exit 0
