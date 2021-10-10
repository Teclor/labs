use warnings;
use strict;

my $rootDir = '';
my $inFilePath = "${rootDir}in5.txt";
my $outFilePath = "${rootDir}out5.txt";
my $textFromFile = '';
open(my $fileHandle, '<', $inFilePath) or die ("Error while opening file $inFilePath: $!\n"); # открываем для чтения
while (my $line = <$fileHandle>) {
    $textFromFile .= $line;
}
close($fileHandle);
print("Input text:\n$textFromFile\nOutput:\n");
my @words = split(/\W+/, $textFromFile); # разделяем по всем последовательностям символов, не являющимися буквами
my $wordsAsText = "";

foreach my $word (@words) {
    if (length($word) <= 5) { # проверяем, что длина слова не более 5 символов
        $wordsAsText .= "$word\n"; # записываем в общий список слов в виде строки
    }
}

print($wordsAsText);

open($fileHandle, '>', $outFilePath) or die ("Error while opening file $outFilePath: $!\n"); # открываем для записи\
print($fileHandle $wordsAsText);
close($fileHandle);

