for i in `seq 0 $2`
do
        ./main <./skaTesty/$1/in/ska$i.in >out

        if [ "$(diff -b out ./skaTesty/$1/out/ska$i.out)" != "" ]
        then
                echo $"WA"
                cat out
                cat ./skaTesty/$1/out/ska$i.out
                exit 1

        else
                echo $i
        fi
done
