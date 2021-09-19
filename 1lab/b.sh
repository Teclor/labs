fileName=$1;
lineCount=$(wc -l $1 | grep -Po "\\d+");
wordCount=$(wc -w $1 | grep -Po "\\d+");
echo "Lines: ${lineCount}. Words: ${wordCount}.";
