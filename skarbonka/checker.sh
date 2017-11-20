#!/bin/bash
for i in {1..999} 
do
    #./main <'./ska_srednie/in/in$i.in' >out

    if [ diff out ./ska_srednie/out/out"$i".out -ne ""]
    then
        echo $"WA"
    else
        echo $"OK"
    fi
done

