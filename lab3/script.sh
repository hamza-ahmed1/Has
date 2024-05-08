#!/bin/bash

read -p "Enter num " num
i=1
while [ $i -le 10 ]
do
	echo $num " * " $i " = "$((num*i))
	((i++)) 
done
