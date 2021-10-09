# Записано арифметическое выражение вида
# 12+22+31+44+87+7.
# Сформируйте массив слагаемых. Вычислите сумму и вывести ее на экран.
use warnings;
use strict;

my $expression = "12+22+31+44+87+7"; # = 34 + 75 + 94 = 203

print("Input data:\n$expression\nOutput:\n");

my @expressionParts = split ("\\+", $expression);
my $result = 0;
foreach my $part (@expressionParts) {
    $result += int($part);
}
print($result);
