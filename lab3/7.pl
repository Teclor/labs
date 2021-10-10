use warnings;
use strict;

my $rootDir = '';
my $inFilePath = "${rootDir}in7.txt";
my $outFilePath = "${rootDir}out7.txt";
my $textFromFile = '';
open(my $fileHandle, '<', $inFilePath) or die ("Error while opening file $inFilePath: $!\n"); # открываем для чтения
while (my $line = <$fileHandle>) {
    $textFromFile .= $line;
}
close($fileHandle);

print("Input text:\n$textFromFile\n");

my @words = $textFromFile =~ m/\w+/g;

my $counter = 1;
my $numberedWords = "";

for my $word (@words) {
    $numberedWords .= $counter++ . ". $word\n";
}

open($fileHandle, '>', $outFilePath) or die ("Error while opening file $outFilePath: $!\n"); # открываем для записи\
print($fileHandle $numberedWords);
close($fileHandle);
