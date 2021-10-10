use warnings;
use strict;

my $rootDir = '';
my $inFilePath = "${rootDir}in6.txt";
my $textFromFile = '';
open(my $fileHandle, '<', $inFilePath) or die ("Error while opening file $inFilePath: $!\n"); # открываем для чтения
while (my $line = <$fileHandle>) {
    $textFromFile .= $line;
}
close($fileHandle);

print("Input text:\n--------\n$textFromFile\n--------\n");

my $linesCount = () = ($textFromFile =~ m/(^.+(?=\n?)|(?<=\n).+)/g); # ищем строку с началом строки до первого переноса строки, или начинающуюся с символа переноса строки, присваиваем её массиву и берём скалярное значение от него
my $wordCount = () = ($textFromFile =~ /\w+/g); # ищем все вхождения сочетаний буквенных символов
my $letterCount = () = ($textFromFile =~ /\w/g); # ищем все вхождения буквенных символов
$\ = "\n";
print("Input file contains:");
print("$letterCount letters");
print("$wordCount words");
print("$linesCount lines");

