#!/bin/bash

for file in $(ls *.$1)
do
     if [ -f $file ];
     then
          rm -i $file
     fi
done
