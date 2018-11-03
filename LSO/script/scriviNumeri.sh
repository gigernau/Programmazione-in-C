#!/bin/bash

#numere da 20 a 10
num=20
#finche è falsa
until [ $num -lt 10 ];
do
     echo $num
     #decrementa
     num=$((num-1))
done
