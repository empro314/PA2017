#!/bin/bash

for i in {0..999}
do
	./main <./ska_srednie/in/in$i.in >out

	if [ "$(diff out ./ska_srednie/out/out$i.out)" != "" ]
	then
		echo $"WA"
		cat out
		cat ./ska_srednie/out/out"$i".out
		exit 1

	else
		echo $"OK"
	fi
done
