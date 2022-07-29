#!/bin/bash

read dictionary
read grid
#get's the dictionary and grid files

RUN_1=`./a.out $dictionary $grid | tail -1`

RUN_2=`./a.out #dictionary $grid | tail -1`

RUN_3=`./a.out #dictionary $grid | tail -1`

RUN_4=`./a.out #dictionary $grid | tail -1`

RUN_5=`./a.out #dictionary $grid | tail -1`
#runs the files 5 times

echo $((($RUN_1+$RUN_2+$RUN_3+$RUN_4+$RUN_5)/5))
#get's the average
