#!/bin/bash
count=0;

while [ -n "$1" ]
do
	count=$[ $count + 1 ];
	echo "Parameter №$count = $1";
	shift;
done

echo "Total parameters count: $count";
