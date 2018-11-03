#!/bin/bash

#copia $1 in dir$2
#controlla che i parametri siano 2
if [ $# -ne 2 ]
then
     echo "bash: $0: Wrong argumenrts's number"
     exit 1
fi


file=$1; destdir=$2

#controlla che $1 sia un file e $2 una directory
if ! [ -d "$destdir" ] || ! [ -f "$file" ];
then 
     echo "bash: copiaFile: Usage copiaFile <file> <dir>"; 
     exit 1;
else
	#copia file in destdir
     until cp $file $destdir;
     do
          echo "Attempt to copy failed. Waiting...";
          sleep 4
     done
fi

