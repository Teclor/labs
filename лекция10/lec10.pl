use strict;
use warnings;
use locale;
use Table;

my $table=[
    {name=>'Ivanov', email=>'ib@as.ru', region=>122},
    {name=>'Petrov', email=>'pet@pasd.su', region=>121},
    {name=>'Sergeev', email=>'serge@mail.ru', region=>167}
];

my $new_row={name=>'Sidorov', email=>'sidr@mail.ru', region=>163};

my $t = Table->create();

$t->load($table);
$t->add_row($new_row);
$t->print;

print "--------\n";

$t->del_row(1);
$t->print;

my @order=('name','email','region');
print $t->ordered_html(1,\@order);

$t->save_html(' 0', \@order, "save.html");