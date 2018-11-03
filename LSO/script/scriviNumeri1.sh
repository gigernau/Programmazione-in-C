#! /bin/bash

COUNTER=0
#finchè è vera
while [ $COUNTER -lt $1 ];
do
     echo il valore di counter è $COUNTER
     COUNTER=$((COUNTER+1))
done
