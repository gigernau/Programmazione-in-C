#!/bin/bash


#copia i file cercati nella myhome del tipo parametro 1
#e li copia nella cartella file$1
myhome="/home/gigernau/Scrivania/LSO"

echo "num file trovati $(find $myhome -name "*.$1" | grep -c "\.$1$")"

mkdir file$1

for file in $(find $myhome -name "*.$1")
do
if [ -f $file ];
then
     cp $file file$1
fi
done
