use strict;

$\ = "\n";
# -----------------------работа с файлами---------------------
sub getFileContents {
    my $fileName = shift;
    my $inFilePath = "task_2_in/$fileName.txt";
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
    my $outFilePath = "task_2_out/$fileName.txt";
    open (my $fileHandle, '>:encoding(UTF-8)', $outFilePath) or die ("Error while opening file $outFilePath: $!\n"); # открываем файл для перезаписи
    print $fileHandle $textForFile;
    close($fileHandle);
}
# -----------------------/работа с файлами---------------------

sub replaceInFile {
    my $fileName = shift;
    my $replaceFunc = shift;
    putFileContents($fileName, $replaceFunc->(getFileContents($fileName)));
}

# 1.	Заменить первое вхождение слова, состоящего только из букв «a» (регистр не важен) на слово «argh». Примеры замен: «There’ll be no more "Aaaaaaaaaaaaaaa"» ! «There’ll be no more "argh"».
replaceInFile('2_1', sub { my $str = $_[0]; $str =~ s/\ba+\b/$1argh$3/ig; return $str; });
# 2.	Поменять местами две первых слова в тексте. Примеры замен: «this is a text» ! «is this a text», «(This, ) is also a text» ! «(is, ) This also a text».
replaceInFile('2_2', sub { my $str = $_[0]; $str =~ s/(\b\w+\b)(\W+?)(\b\w+\b)/$3$2$1/; return $str; });
# 3.	Поменять местами две первых буквы в каждом слове. Примеры замен: «this is a text» ! «htis si a etxt».
replaceInFile('2_3', sub { my $str = $_[0]; $str =~ s/\b(\w)(\w)/$2$1/g; return $str; });
# 4.	Заменить все вхождения двух одинаковых букв подряд на одну букву. Примеры замен: «attraction» ! «atraction», «buzzzz» ! «buzz».
replaceInFile('2_4', sub { my $str = $_[0]; $str =~ s/(\w)(\1)/$1/g; return $str; });
# 5.	Заменить все вхождения нескольких одинаковых букв подряд на одну букву. Примеры замен: «attraction» ! «atraction», «buzzzz» ! «buz».
replaceInFile('2_5', sub { my $str = $_[0]; $str =~ s/(\w)(\1+)/$1/g; return $str; });
# 6.	Заменить все числа кратные 10 на их частное от деления на 10. В этой задаче на вход подаются числа, разделенные пробелами. Примеры замен: «1 2 10 12 20 123 239 566 12800» ! «1 2 1 12 2 123 239 566 1280».
replaceInFile('2_6', sub { my $str = $_[0]; $str =~ s/(\d+)/int($1 % 10) == 0 ? int($1\/10) : $1/ge; return $str; });
# 7.	Удалить символы после каждой открывающейся скобки до ближайшей закрывающейся. Примеры замен: «(word) outside (1 open (2 open)» ! «() outside ()».
replaceInFile('2_7', sub { my $str = $_[0]; $str =~ s/(\(.*?\))/()/g; return $str; });
# 8.	Будем называть хорошей строку, состоящую хотя бы из двух символов, если она начинается с буквы «a» и заканчивается буквой «a». Заменить все вхождения трех хороших строк подряд на строку
# «bad». При этом замена должна производиться как только соответствующая подстрока встретилась. Примеры замен: «abaacaada»! «bad», «abaacaadaa» ! «bada».
replaceInFile('2_8', sub { my $str = $_[0]; $str =~ s/((([^a]*(a.*?a)[^a]*)|([^a]*(a.*a)[^a]*)){3})/bad/g; return $str; });
