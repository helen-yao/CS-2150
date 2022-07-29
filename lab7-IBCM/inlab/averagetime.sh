#!/bin/bash


echo "enter the exponent for counter.cpp"

read exp
sum=0
avg=0

#get the input, if it is quit it will quit

if [ "$exp" == "quit" ]; then
    exit
else
    for i in 1 2 3 4 5 ; do
	echo "Running iteration $i ..."
	eval "RUNTIME=`./a.out $exp | tail -1`"
	echo "time taken $RUNTIME ms"
	sum=$(( sum + $RUNTIME ))
    done
fi
    echo "5 iterations took $sum ms"
    echo "Average time was $(( sum/5 )) ms"
