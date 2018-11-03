#!/bin/bash

#controlla che ci sia un solo parametro
if test $# -ne 1
then
     echo "wrong number og parameters $#"
     echo "Usage: $0 param"
fi

COUNTER=0

#finche il count è < di $1
while [ $COUNTER -lt $1 ];
do   
	#incrementa
     COUNTER=$((COUNTER+1))
     #crea file nume count
     touch node$COUNTER.html   
done
