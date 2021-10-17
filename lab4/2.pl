use strict;
use warnings;

# -----------------------открытие и считывание файла---------------------
my $rootDir = '';
my $inFilePath = "${rootDir}in2.txt";
my $textFromFile = '';
open(my $fileHandle, '<:encoding(UTF-8)', $inFilePath) or die ("Error while opening file $inFilePath: $!\n"); # открываем для чтения
while (my $line = <$fileHandle>) {
    $textFromFile .= $line;
}
close($fileHandle);
print ("Input:\n" . $textFromFile . "\nOutput:\n");
# -----------------------/открытие и считывание файла---------------------

$\ = "\n";
my %wordsHash = ();

my @words = $textFromFile =~ m/\w+/g; # выбираем все последовательности, состоящие из подряд идущих букв
foreach my $word (@words) {
    my $firstLetter = lc(substr($word, 0, 1)); # берём первую букву и приводим её к нижнему регистру
    if (!defined($wordsHash{$firstLetter})) {
        $wordsHash{$firstLetter} = $word;
    }
    else {
        $wordsHash{$firstLetter} .= " $word";
    }
}


my @hashKeys = sort(keys(%wordsHash)); # сортируем ключи, чтобы вывести в алфавитном порядке
foreach my $key (@hashKeys) {
    print ("$key: $wordsHash{$key}");
}