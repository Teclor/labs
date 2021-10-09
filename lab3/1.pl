use strict;
use warnings;

my $rootDir = 'C:\Users\Core i7\Desktop\Studying\Perl\lab3\\';
my $inFileName = "${rootDir}in1.txt";
my $outFileName = "${rootDir}out1.txt";

open(my $fileHandle, '<', $inFileName) or die ("Error while opening file $inFileName: $!\n"); # открываем файл для чтения с начала
my $textFromFile = '';
while (my $line = <$fileHandle>) {
    $textFromFile .= $line; # записываем построчно текст из файла
}
close($fileHandle);
print($textFromFile);

open ($fileHandle, '>', $outFileName) or die ("Error while opening file $inFileName: $!\n"); # открываем файл для перезаписи
my @splitText = split(/\s/, $textFromFile); # разделяем текст из файла по любым пробельным сивмолам
$\ = "\n"; # разделять вывод символом новой строки
my $availableLetter = 'r'; # буква, слова начинающиеся с которой будут записываться во второй файл
foreach my $word (@splitText) {
    my $firstLetter = substr($word, 0, 1); # первая буква в слове
    if (lc($firstLetter) eq $availableLetter) { # если приведённая к нижнему регистру первая буква слова совпадает с нужной
        print $fileHandle $word; # записать слово в файл
    }
}
close($fileHandle);
