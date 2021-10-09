# Каждое слово предложения записать с новой строки.
use strict;
use warnings;

my $sentence = "Let's write every word on a separate line";

print("Input data:\n$sentence\nOutput:\n");

my @words = split (" ", $sentence);

print "$_\n" foreach @words;