use strict;
use warnings FATAL => 'all';

$\ = "\n";
# -----------------------работа с файлами---------------------
sub getFileContents {
    my $fileName = shift;
    my $inFilePath = "task_1/$fileName.txt";
    my $textFromFile = '';
    open(my $fileHandle, '<:encoding(UTF-8)', $inFilePath) or die ("Error while opening file $inFilePath: $!"); # открываем для чтения
    while (my $line = <$fileHandle>) {
        $textFromFile .= $line;
    }
    close($fileHandle);
    return $textFromFile;
}

sub putFileContents {
    my $fileName = shift;
    my $textForFile = shift;
    my $outFilePath = "$fileName.txt";
    open (my $fileHandle, '>>:encoding(UTF-8)', $outFilePath) or die ("Error while opening file $outFilePath: $!\n"); # открываем файл для дозаписи в конец
    print $fileHandle $textForFile;
    close($fileHandle);
}
# -----------------------/работа с файлами---------------------
# --------------вывод строк, соответствующих регулярному выражению--------
sub showMatchedStringsInFile {
    my $fileName = shift;
    my $checkFunction = shift;
    my $textFromFile = getFileContents($fileName);
    my $outText = "-------Input from $fileName :--------\n" . $textFromFile . "\n--------Output for $fileName:--------";
    print ($outText);
    $outText .= "\n";
    my @linesFromText = split("\n", $textFromFile);
    my $checkedLines = "";
    for my $line (@linesFromText) {
        if ($checkFunction->($line)) {
            print $line;
            $checkedLines .= $line . "\n";
        }
    }
    chomp($checkedLines);
    $outText .= $checkedLines;
    putFileContents('task_1_out', $outText);
}
# -------------/вывод строк, соответствующих регулярному выражению--------

# 1.	Строки, содержащие «cat» в качестве подстроки два раза.
# Пример строк, которые подходят: «catcat», «cat and cat».
# Пример строк, которые не подходят: «catac», «cat», «ccaatt».
showMatchedStringsInFile("1_1", sub { my @matches = $_[0] =~ /cat/g; return scalar(@matches) == 2}); # проверяем на соответствие и чтобы встречалось ровно два раз
# 2.	Строки, содержащие две буквы «z», между которыми ровно три символа.
# Пример строк, которые подходят: «zabcz», «zzxzz».
# Пример строк, которые не подходят: «zzz», «zz», «zxz», «zzxzxxz».
showMatchedStringsInFile("1_2", sub { return $_[0] =~ /z.{3}z/});
# 3.	Строки, содержащие две буквы из множества {«x», «y», «z»}, между которыми от 5 до 17 символов.
# Пример строк, которые подходят: «xabcabcz», «zzzzzzzzzzzzzzzzzz».
# Пример строк, которые не подходят: «xx», «xyz», «zwzwwz».
showMatchedStringsInFile("1_3", sub { return $_[0] =~ /[xyz].{5,17}[xyz]/});
# 4.	Строки, содержащие в качестве слова число.
# Пример строк, которые подходят: «Year is 2009.», «1 is a number», «3.1415 matches because . is not a word char».
# Пример строк, которые не подходят: «Not2Bad», «No digits here».
showMatchedStringsInFile("1_4", sub { return $_[0] =~ /(^|\s+)[0-9]+\.?[0-9]*(\s+|$)/});
# 5.	Строки, содержащие обратный слеш.
# Пример строк, которые подходят: «\w denotes word character».
# Пример строк, которые не подходят: «No slashes here».
showMatchedStringsInFile("1_5", sub { return $_[0] =~ /\\/});
# 6.	Строки, содержащие слово внутри произвольного текста, не содержащего скобок, в скобках.
# Пример строк, которые подходят: «good (excellent) phrase», «good (too bad) phrase», «good ((recursive)) phrase».
# Пример строк, которые не подходят: «word () is not () in brackets», «bad (() recursive) phrase», «no brackets here».
showMatchedStringsInFile("1_6", sub { return $_[0] =~ /\(\w+\)/}); #в подходящих примерах ошибка: (too bad) не слово, а два слова! сделал по заданию
# 7.	Строки, не содержащие ведущих или конечных пробельных символов.
# Пример строк, которые подходят: «Good string», «».
# Пример строк, которые не подходят: « bad string», «bad string », « very bad string ».
showMatchedStringsInFile("1_7", sub { return $_[0] !~ /^\s|\s$/});
# 8.	Строки, содержащие слово, состоящее из двух равных частей (тандемный повтор).
# Пример строк, которые подходят: «blabla is a tandem repetition» «123123 is good too».
# Пример строк, которые не подходят: «go go», «aaa»,.
showMatchedStringsInFile("1_8", sub { return $_[0] =~ /\b(.+?)(\1)\b/});
# 9.	Строки, содержащие двоичную запись числа, кратного 3.
# Пример строк, которые подходят: «0», «10010».
# Пример строк, которые не подходят: «00101», «Not a number», «11», «00».
showMatchedStringsInFile("1_9", sub { return $_[0] =~ /(^|\D)(1(01*0)*1|0)+(\D|$)/});
# почему три не кратно трём? 11 - три в двоичной записи, должно подпадать под условие, также должно подпадать 00, т.к. это то же самое, что 0
# есть правило для проверки кратности 11 у десятичных чисел, 11 - это три в двоичной записи, поэтому можем проверять с помощью этого правила кратность 3 двоичной записи числа
# пояснение к регулярному выражению: проверить кратно ли число трём мы можем последовательно складывая его значащие разряды с чередованием знаков - и +,
# если в конце получаем ноль, то двоичная запись числа кратно 3
# таким образом, в значащих разрядах должно быть чётное количество единиц, при этом количество единиц в разрядах каждой чётности также должно быть чётно
