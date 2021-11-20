package Table;
use strict;
use warnings;
use locale;
sub create{
    my ($myself, $ref)=@_;
    $ref=[];

    bless $ref, $myself;
}

sub print{
    my $this=shift;

    for(@{$this}){
        if(defined $_){
            for my $name (keys %{$_}){
                print $_->{$name}, "\t";
            }
            print "\n";
        }
    }
}

sub load{
    my $self = shift;
    my $table = shift;

    for (@{$table}){
        push @{$self},$_;
    }
}

sub add_row{
    my $self = shift;
    my $row = shift;

    push @{$self},$row;
    return;
}

sub get_row{
    my $self = shift;
    my $num = shift;
    return $self->[$num];
}

sub del_row{
    my $self = shift;
    my $num = shift;
    $self->[$num]=undef;
    return;
}

sub html{
    my $self=shift;
    my $border=shift;
    my $str="<table border=$border>";

    for my $row(@{$self}){
        $str.="<tr>";
        for(keys %{$row}){
            $str.="<td>";
            $str.=$row->{$_};
            $str.="</td>\n"
        }
        $str.="</tr>";
    }
    $str.="</table>";
    return $str;
}

sub ordered_html{
    my $self=shift;
    my $border=shift;
    my $order=shift;
    my $str="<table border=$border>";

    for my $row (@{$self}){
        no warnings 'uninitialized';
        $str.="<tr>";
        for(@{$order}){
            $str.="<td>";
            $str.=$row->{$_};
            $str.="</td>";
        }
        $str.="</tr>\n";
    }
    $str.="</table>";
    return $str;
}

sub save_html{
    my $self = shift;
    my $border = shift;

    $border=1 unless defined $border;
    my $order=shift;
    $order=[keys @{$self->[0]}] unless defined $order;
    my $file=shift;
    $file="index.html" unless defined $file;
    open (OUT, ">", $file) or die;
    print OUT $self->ordered_html($border, $order);
    close OUT;
    return;
}
1;