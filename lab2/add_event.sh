#!/bin/bash
inputString=$1;
targetFile=~/".myevents";
confFile=~/"myevents.conf";

if (test -f $confFile); then
	showLineQuantity=$(head -n 1 $confFile | grep -o -E "[0-9]+");
else
	showLineQuantity=7;
fi

if [ -z "$inputString" ]; then
	tail -n $showLineQuantity "$targetFile";
else
	dateTime=$(date +"%d.%m.%Y %H:%I:%S");
	echo "$dateTime $inputString" >> "$targetFile";
fi



