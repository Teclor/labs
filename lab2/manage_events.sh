#!/bin/bash
inputString=$1;
targetFile=~/".myevents";
confFile=~/"myevents.conf";
displayDateStart=$2;

if (test -f $confFile); then
	showLineQuantity=$(head -n 1 $confFile | grep -o -E "[0-9]+");
else
	showLineQuantity=7;
fi

if [ -z "$inputString" ]; then
	tail -n $showLineQuantity "$targetFile";
else
	sedMakeCorrectDatePattern='s/\([0-9]\+\)\.\([0-9]\+\)\.\([0-9]\+\)\(.*\)/\2\/\1\/\3/';
	inputDate=$(date -d $(sed "$sedMakeCorrectDatePattern" <<< "$inputString") +%s  2> /dev/null);
	if [ -z "$inputDate" ]; then
		dateTime=$(date +"%d.%m.%Y,%H:%I:%S");
		echo -e "$dateTime\t$inputString" >> "$targetFile";
	else
		resultLines='';
		while read -r line; do
			dateFromLine=$(date -d $(sed "$sedMakeCorrectDatePattern" <<< "$line") +%s);
			if [[ $dateFromLine -ge "$inputDate" ]]; then
				echo $line;
			fi
		done < "$targetFile";
	fi
fi

