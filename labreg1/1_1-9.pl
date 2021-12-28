use strict;
use warnings FATAL => 'all';

# -----------------------открытие и считывание файла---------------------
sub getFileContents {
    my $fileName = shift;
    my $inFilePath = "$fileName.txt";
    my $textFromFile = '';
    open(my $fileHandle, '<:encoding(UTF-8)', $inFilePath) or die ("Error while opening file $inFilePath: $!\n"); # открываем для чтения
    while (my $line = <$fileHandle>) {
        $textFromFile .= $line;
    }
    close($fileHandle);
    return $textFromFile;
}
# -----------------------/открытие и считывание файла---------------------
# --------------вывод строк, соответствующих регулярному выражению--------
sub showMatchedStringsInFile {
    my $fileName = shift;
    my $checkFunction = shift;
    my $textFromFile = getFileContents($fileName);
    print ("-------Input from $fileName :--------\n" . $textFromFile . "\n--------Output for $fileName:--------\n");
    my @linesFromText = split("\n", $textFromFile);
    $\ = "\n";
    for my $line (@linesFromText) {
        if ($checkFunction->($line)) {
            print $line;
        }
    }
}
# -------------/вывод строк, соответствующих регулярному выражению--------
# 1.	Строки, содержащие «cat» в качестве подстроки два раза. Пример строк, которые подходят: «catcat», «cat and cat». Пример строк, которые не подходят: «catac», «cat», «ccaatt».
showMatchedStringsInFile("1_1", sub { my @matches = $_[0] =~ /cat/g; return scalar(@matches) == 2});
# 2.	Строки, содержащие две буквы «z», между которыми ровно три символа. Пример строк, которые подходят: «zabcz», «zzxzz». Пример строк, которые не подходят: «zzz», «zz», «zxz», «zzxzxxz».
# 3.	Строки, содержащие две буквы из множества {«x», «y», «z»}, между которыми от 5 до 17 символов. Пример строк, которые подходят: «xabcabcz», «zzzzzzzzzzzzzzzzzz». Пример строк, которые не подходят: «xx», «xyz», «zwzwwz».
#     4.	Строки, содержащие в качестве слова число. Пример строк, которые подходят: «Year is 2009.», «1 is a number», «3.1415 matches because . is not a word char». Пример строк, которые не подходят: «Not2Bad», «No digits here».
#     5.	Строки, содержащие обратный слеш. Пример строк, которые подходят: «\w denotes word character». Пример строк, которые не подходят: «No slashes here».
#     6.	Строки, содержащие слово внутри произвольного текста, не содержащего скобок, в скобках. Пример строк, которые подходят: «good (excellent) phrase», «good (too bad) phrase», «good ((recursive)) phrase». Пример строк, которые не подходят: «word () is not () in brackets», «bad (() recursive) phrase», «no brackets here».
#     7.	Строки, не содержащие ведущих или конечных пробельных символов. Пример строк, которые подходят: «Good string», «». Пример строк, которые не подходят: « bad string», «bad string », « very bad string ».
#     8.	Строки, содержащие слово, состоящее из двух равных частей (тандемный повтор). Пример строк, которые подходят: «blabla is a tandem repetition» «123123 is good too». Пример строк, которые не подходят: «go go», «aaa»,.
#     9.	Строки, содержащие двоичную запись числа, кратного 3. Пример строк, которые подходят: «0», «10010». Пример строк, которые не подходят: «00101», «Not a number», «11», «00».


