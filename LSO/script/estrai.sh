#!/bin/bash

#primi 3 chaer di $1 in $3
#ultimi 2 char di $2 append $3
head -3 $1 > $3
tail -2 $2 >> $3
