#!/bin/bash
IFS=':';
read -ra PATH_LIST <<< "$PATH";

for path in "${PATH_LIST[@]}"; do
	if [ ! -d "$path" ]; then
		echo "Path $path is not correct!";
	fi
done
