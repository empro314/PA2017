#!/bin/bash

for i in {1..20}
do
	./main <./ban/ban$i.in >out

	if [ "$(diff out ./ban/ban$i.out)" != "" ]
	then
		echo $"WA"
		#cat out
		#cat ./ska_srednie/out/out"$i".out
		#exit 1

	else
		echo $"OK"
	fi
done
