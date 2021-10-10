use warnings;
use strict;

my $rootDir = '';
my $inFilePath = "${rootDir}in3.txt";
my $outFilePath = "${rootDir}out3.txt";
my $textFromFile = '';
open(my $fileHandle, '<', $inFilePath) or die ("Error while opening file $inFilePath: $!\n"); # открываем для чтения
while (my $line = <$fileHandle>) {
    $textFromFile .= $line;
}
close($fileHandle);

print("Input text:\n" . $textFromFile);

my @paragraphs = split(/\n\s+/, $textFromFile); # считаем абзацем символ новой строки и 1+ пробельных символов после него
print ("\nParagraphs:\n");
my $counter = 1;

open($fileHandle, '>', $outFilePath) or die ("Error while opening file $outFilePath: $!\n"); # открываем для записи

foreach my $paragraph (@paragraphs) {
    print($counter . " ");
    print($paragraph);
    print("\n--\n");
    if ($counter % 2 == 0) { # выводим каждый второй абзац
        print($fileHandle $paragraph . "\n");
    }
    $counter++;
}

close($fileHandle);