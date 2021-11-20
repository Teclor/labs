use strict;
use warnings;

use File::Basename qw(dirname);
use Cwd  qw(abs_path);
use lib dirname(dirname abs_path $0) . '/lab5/';
use Table;

my $fileName = "lab5_references_3_variant.txt";
my $table = Table->new($fileName);
$table->load();

my $instructionText = "Enter the command:\nq - quit\np - print the table\nl - load and print the table from file\ns - search in the table\na - add new line\ndel - delete by id\nsort - sort by field\nsave - save the table to file\n";
print ($instructionText);
while (<>) {
    my $command = $_;
    chomp($command);
    if ($command eq 'q') {
        exit 0;
    }
    if ($command eq 'p') {
        print($table->get());
    }
    if ($command eq 'l') {
        $table->load();
        print($table->get());
    }
    if ($command eq 's') {
        print("Enter the text you want to search: ");
        my $searchText = <>;
        chomp($searchText);
        print("\n");
        print($table->search($searchText));
    }
    if ($command eq 'a') {
        $table->addLine();
        print($table->get());
    }
    if ($command eq 'del') {
        print("Enter the ID of an element: ");
        my $elementId = <>;
        chomp($elementId);
        print("\n");
        $table->deleteLine($elementId);
        print($table->get());
    }
    if ($command eq 'sort') {
        print("Enter the column number to sort BY: ");
        my $sortColumn = <>;
        chomp($sortColumn);
        print("\n");
        $table->sortByColumn($sortColumn);
        print($table->get());
    }
    if ($command eq 'save') {
        $table->saveToFile();
        $table->load();
    }
    print ($instructionText);
}
