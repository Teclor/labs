#!/bin/bash

users=$(cat /etc/passwd)
IFS=$'\n'
for var in $users
do
	leftbord=$(expr index $var :)
	rightbord=${var##*:}
	echo "$var";
	# echo "User: "${var:0:$leftbord-1}", program: "$rightbord""
done