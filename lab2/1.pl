# Текст содержит список нумерованных предложений, начинающихся с новой строки. Сформировать массив этих предложений.
# Вывести его на экран с разделителем элементов знаком процента.
use warnings;
use strict;

my $text = "1. The first sentence.
2. The second sentence.
3. The third sentence.";

print("Input data:\n$text\nOutput:\n");

my @lineFromText = split (/\n?\d+\. /, $text);
$\ = "%";
my $lastArrayElementIndex = $#lineFromText;
my @lineFromText = @lineFromText[1..$lastArrayElementIndex]; # удаляем первую пустую строку
foreach my $line (@lineFromText){
    print ($line);
}

# если нужно сохранить нумерацию
$\ = "";
print("\nPreserve the numeration:\n");
my @lineFromText = split ("\n", $text);
$\ = "%";
foreach my $line (@lineFromText){
    print ($line);
}
