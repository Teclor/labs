# Строка имеет вид "число+число:число+число". Вычислить соответствующее значение выражения.
use strict;
use warnings;

my $str = "25+25:5+5";
print("Input data:\n$str\nOutput:\n");

my @additionParts = split ("\\+", $str); # разделяем на части со слагаемыми
my $additionResult = 0;
foreach my $additionPart (@additionParts) { # проходимся по всем слагаемым
    my $tmpAdditionPart = $additionPart;
    if (index($additionPart, ':') != -1) { # если в слагаемом есть знак деления
        my @divisionParts = split (":", $tmpAdditionPart); # разделяем по знаку деления
        $tmpAdditionPart = $divisionParts[0]; # в качестве первого делимого берём самое левое в строке число (самое первое в массиве после разделения)
        my $maxDivisionPartIndex = $#divisionParts; # индекс последнего элемента в массиве
        foreach my $divisionPart (@divisionParts[1..$maxDivisionPartIndex]) { # по всем элементам кроме нулевого
            $tmpAdditionPart /= $divisionPart; # делим уже имеющийся результат на следующий элемент массива элементов для деления
        }
    }
    $additionResult += $tmpAdditionPart; # добавляем слагаемое к общему результату
}

print($additionResult);


