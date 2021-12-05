#!/bin/bash
pathToRemove=$1;
pathToRemovedArchive=~/".deleted_files/archive.tar";
pathToRemovedInfo=~/".removed-files";
infoDelimeter="///";

if [[ -f "$pathToRemove" || -d "$pathToRemove" ]]; then
  absolutePath="$(readlink --canonicalize "$pathToRemove")";
  baseName=$(basename "$absolutePath");
  dirPath=$(dirname "$absolutePath");

  currentDate=$(date +"%d%m%Y_%H%I%S");
  baseNameWithDate=$(echo "$baseName" | sed -e "s/\([^.]*\)\(\.\{0,1\}.*\)/\1_$currentDate\2/");
  newAbsolutePath="${dirPath}/$baseNameWithDate";

  mv "$absolutePath" "$newAbsolutePath";
  tar rvf "$pathToRemovedArchive" -C "$dirPath" "$baseNameWithDate" --remove-files;

  echo "$baseNameWithDate${infoDelimeter}$absolutePath" >> "$pathToRemovedInfo";
else
  echo "Please, enter correct path to delete as the first argument";
fi
