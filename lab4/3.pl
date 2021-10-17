use strict;
use warnings;

# -----------------------открытие и считывание файла---------------------
my $rootDir = '';
my $inFilePath = "${rootDir}in3.txt";
my $textFromFile = '';
open(my $fileHandle, '<:', $inFilePath) or die ("Error while opening file $inFilePath: $!\n"); # открываем для чтения
while (my $line = <$fileHandle>) {
    $textFromFile .= $line;
}
close($fileHandle);
print ("Input:\n" . $textFromFile . "\nOutput:\n");
# -----------------------/открытие и считывание файла---------------------

$\ = "\n";
my %wordLengthHash = ();

my @words = $textFromFile =~ m/\w+/g; # выбираем все последовательности, состоящие из подряд идущих букв
foreach my $word (@words) {
    my $wordLength = length($word); # количество букв в слове
    if (!defined($wordLengthHash{$wordLength})) {
        $wordLengthHash{$wordLength} = 1;
    }
    else {
        $wordLengthHash{$wordLength}++;
    }
}


my @hashKeys = keys(%wordLengthHash);
foreach my $key (@hashKeys) {
    print ("Length: $key, Count: $wordLengthHash{$key}");
}