#!/bin/bash
if [ -n "$1" ]; then
	fileName=$1;
	lineCount=$(wc -l fileName | grep -Po "\\d+");
	wordCount=$(wc -w fileName | grep -Po "\\d+");
	echo "Lines: ${lineCount}. Words: ${wordCount}.";
else
	echo "Please, enter the file name";
	exit 1;
fi
