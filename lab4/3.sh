#!/bin/bash
userName=$1;
directory=$2;

if [[ -n "$userName" && -n "$directory" ]]; then
  su "$userName" -c "du -hs $directory"
else
  echo "Please, enter correct user name as the first argument and directory path as the second.";
fi