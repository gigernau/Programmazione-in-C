#!/bin/bash

#cerca i file in ls con la prima lettera maiuscola
for file in $(ls)
do
	if [ -d $file ]
	then
		a=$(echo $file | cut -c1)
		b=-$(echo $a | grep "[A-Z]")
		
		if [ $b != - ]
		then
		     echo $file >> fileDir
		fi
	fi
done


