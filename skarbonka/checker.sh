i=0
while [ $i -le 999 ]
do
    ./main <./ska_srednie/in/in$i.in >out
 
    if [ `diff out ./ska_srednie/out/out"$i".out` -ne "" ]
    then
        echo $"WA"
    else
        echo $"OK"
    fi

    i=$[i+1]
done
