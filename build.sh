#!/bin/bash
# gcc *.c -fsanitize=address,undefined,leak -Wpedantic -O0
if [ $1 = graph ]; then
	gcc graph.c linked_list.c main_graph.c -fsanitize=leak -Wall -O1
elif [ $1 = ll ]; then
	gcc linked_list.c main_linked_list.c -fsanitize=leak -Wall -O1
else
	echo 'Needs argument graph or ll'
fi
