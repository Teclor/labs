use warnings;
use strict;

my $rootDir = '';
my $inFilePath = "${rootDir}in4.txt";
my $outFilePath = "${rootDir}out4.txt";
my $textFromFile = '';
open(my $fileHandle, '<', $inFilePath) or die ("Error while opening file $inFilePath: $!\n"); # открываем для чтения
while (my $line = <$fileHandle>) {
    $textFromFile .= $line;
}
close($fileHandle);

print("Input text:\n$textFromFile\n");

my @lines = split("\n", $textFromFile);
my $sums = "";
foreach my $line (@lines) {
    my @additionParts = split(/\s+/, $line); # разделяем по любым пробельным символам в количестве 1 или более
    my $sum = 0;
    foreach my $number (@additionParts) {
        $sum += $number;
    }
    $sums .= "$sum\n"; # сумма для каждой строки на отдельной строке
}

open($fileHandle, '>', $outFilePath) or die ("Error while opening file $outFilePath: $!\n"); # открываем для записи\
print($fileHandle $sums);
close($fileHandle);
