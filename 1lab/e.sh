#!/bin/bas
filesDir=$1;
if [ -n "$filesDir" ]; then
	filesData=$(ls -lQ "$filesDir" | egrep "\-(.{2}|.{5}|.{8})x");
	executableFIles=$(echo "$filesData" | egrep -o "\".+\"$");
	printf "List of executable files:\n$executableFIles\n";
else
	echo "Please, enter the file path as the first argument";
fi
