use warnings;
use strict;

my @digits = (1..9); # диапазон цифр от 1 до 9 включительно
my $multiplicationTable = ""; # переменная с текстом таблицы умножения
foreach my $firstMultiplier (@digits) { # цикл по всем цифрам в качестве первого множителя
    foreach my $secondMultiplier (@digits) { # цикл по всем цифрам в качестве второго множителя
        $multiplicationTable .= ($firstMultiplier * $secondMultiplier) . "\t"; # умножение и табуляция
    }
    $multiplicationTable .= "\n";
}

my $rootDir = 'C:\Users\Core i7\Desktop\Studying\Perl\lab3\\';
my $filePath = "${rootDir}multiplication_table.txt";
open(my $fileHandle, '>', $filePath) or die ("Error while opening file $filePath: $!\n"); # открываем для записи
print($fileHandle $multiplicationTable); # записываем таблицу умножения в файл
close($fileHandle);
