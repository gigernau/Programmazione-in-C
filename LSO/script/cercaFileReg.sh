#!/bin/bash

#cerca file regolari
for file in $(ls)
do
if [ -f $file ] 
then
     echo $file >> fileReg
fi
done
