#!/bin/bash
processName=$1;
if [ -n "$processName" ]; then
  pkill "$processName";
fi