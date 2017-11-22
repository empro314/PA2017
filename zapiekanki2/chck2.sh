#!/bin/bash

for i in {1..12}
do
	./main <./wn/wn$i.in >out

	if [ "$(diff out ./wn/wn$i.out)" != "" ]
	then
		echo $"WA"
		cat ./wn/wn$i.out
		echo '\n'
		cat out
		exit 1

	else
		echo $"OK"
	fi
done
