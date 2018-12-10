#!/bin/sh

for n in `seq 0 16`;
do
  for d in `seq ${n} 16`;
  do
    make run NPROCS=${n} NPINTS=${d} > resultN${n}D${d}.txt;
  done;
done;
