#!/bin/bash

myhome=$HOME

echo "Numero file trovati $(find $myhome -name "*.c" | grep -c "\.c$")"

mkdir fileC 

for file in $(find $myhome -name "*.c")
do 
if [ -f $file ];
then
     cp $file  fileC
fi
done
