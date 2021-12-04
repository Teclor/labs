#!/bin/bash
programName=$1;
if [ -z "$programName" ]; then
	echo "Please, enter the name of the program";
else 
	foundProgram=$(which "$programName");
	if [ -n "$foundProgram" ]; then
		echo "Program was found in system.";
	else
		echo "Program was not found in system.";
	fi
fi
