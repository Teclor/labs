#!/bin/bash
fileNamePart=$1;
pathToRemovedArchive=~/".deleted_files/archive.tar";
pathToRemovedInfo=~/".removed-files";
infoDelimeter="\/\/\/";

if [ -n "$fileNamePart" ]; then
  foundFiles=$(cat "$pathToRemovedInfo" | sed -e "s/\([^$infoDelimeter]*\).*/\1/" | grep ".*${fileNamePart}.*");
  for file in $foundFiles; do
    pathToRestore=$(sed -n "s/\($file${infoDelimeter}\)\(.\+\)/\2/p" "$pathToRemovedInfo");
    restoreDir=$(dirname "$pathToRestore");
    originFileName=$(basename "$pathToRestore");

    test ! -d "$restoreDir" && mkdir "$restoreDir";
    tar -xvf "$pathToRemovedArchive" -C "$restoreDir" "$file";
    mv -T "$restoreDir/$file" "$restoreDir/$originFileName";
  done
else
  echo "Please, enter not empty file name part or date in format dmY_HIS as the first argument."
fi


# tar tvf ~/.deleted_files/archive.tar | awk '{print $6}'