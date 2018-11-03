#!/bin/bash

# cerca i tipi di file in (ls) e li conta -c
for j in txt waw tif png
do
	n=$(ls -l | grep -c ".$j$")
	echo "ci sono $n file di tipo $j"
done

#conta le sotto cartelle
n=$(ls -l | grep -c "^d")
echo "e ci sono $n sottocartelle"
