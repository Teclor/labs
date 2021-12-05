#!/bin/bash
IFS=':'
read -ra pathArray <<<"$PATH"

for path in "${pathArray[@]}"; do
  if [ ! -d "$path" ]; then
    echo "Path $path is not correct!"
  fi
done
