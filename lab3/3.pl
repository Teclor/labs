use warnings;
use strict;

my $rootDir = 'C:\Users\Core i7\Desktop\Studying\Perl\lab3\\';
my $inFilePath = "${rootDir}in3.txt";
my $outFilePath = "${rootDir}out3.txt";
my $textFromFile = '';
open(my $fileHandle, '<', $inFilePath) or die ("Error while opening file $inFilePath: $!\n"); # открываем для чтения
while (my $line = <$fileHandle>) {
    $textFromFile .= $line;
}
close($fileHandle);

print("Input text:\n" . $textFromFile);

my @paragraphs = split(/\n\s/, $textFromFile);
print ("\nParagraphs:\n");
my $counter = 1;

open($fileHandle, '>', $outFilePath) or die ("Error while opening file $outFilePath: $!\n"); # открываем для чтения

foreach my $paragraph (@paragraphs) {
    print($counter . " ");
    print($paragraph);
    print("\n--\n");
    if ($counter % 2 == 1) {
        print($fileHandle $paragraph . "\n");
    }
    $counter++;
}

close($fileHandle);