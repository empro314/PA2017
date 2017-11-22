#!/bin/bash

for i in {1..12}
do
	./main <./2Btesty/$i.in >out

	if [ "$(diff out ./2Btesty/$i.out)" != "" ]
	then
		echo $"WA"
		#cat ./2Btesty/$i.out
		#exit 1

	else
		echo $"OK"
	fi
done
