#!/bin/bash

for i in {1..12}
do
	./brute <./2Btesty/$i.in >out2

	if [ "$(diff out2 ./2Btesty/$i.out)" != "" ]
	then
		echo $"WA"
		#cat ./2Btesty/$i.out
		#exit 1

	else
		echo $"OK"
	fi
done
