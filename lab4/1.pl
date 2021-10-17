use strict;
use warnings;

# -----------------------открытие и считывание файла---------------------
my $rootDir = '';
my $inFilePath = "${rootDir}in1.txt";
my $textFromFile = '';
open(my $fileHandle, '<:encoding(UTF-8)', $inFilePath) or die ("Error while opening file $inFilePath: $!\n"); # открываем для чтения
while (my $line = <$fileHandle>) {
    $textFromFile .= $line;
}
close($fileHandle);
print ("Input:\n" . $textFromFile . "\nOutput:\n");
# -----------------------/открытие и считывание файла---------------------

my @linesFromText = split("\n", $textFromFile);
$\ = "\n";
my %userData = ();
my $firstLineFromFile = $linesFromText[0]; # в задании указано, что нужно построить хеш из строки, поэтому
# берём одну первую строку. Хотя изначально и отмечено, что "Количество строк в файле неизвестно, но больлее одной",
# мы можем хранить только одну пару ключ => значение в хеше, иначе нам придётся создавать хеш хешей, что не является целью данного задания
my @dataParts = split(", ", $firstLineFromFile);
foreach my $dataPart (@dataParts) {
    my @keyAndValue = split(":", $dataPart);
    $userData{$keyAndValue[0]} = $keyAndValue[1];
}

my @hashKeys = keys %userData;

foreach my $key (@hashKeys) {
    print("Key: $key, value: $userData{$key}");
}