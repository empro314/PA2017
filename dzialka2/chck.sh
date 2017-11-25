#!/bin/bash

for i in {1..15}
do
	./starter <./test/$i.in >out2

	if [ "$(diff -b out2 ./test/$i.out)" != "" ]
	then
		echo $"WA"
		#cat ./2Btesty/$i.out
		#exit 1

	else
		echo $"OK"
	fi
done
