package Table; {
    use strict;
    use warnings FATAL => 'all';
    use Exporter qw(import);
    use Try::Tiny;

    our @EXPORT_OK = qw(saveToFile addLine deleteLine getLineIndexById get load search new sortByColumn);

    sub new {
        my ($class) = shift;

        my $self = {
            file        => shift,
            columns     => (),
            lines       => (),
            columnCount => 0,
        };

        bless $self, $class;
    }

    sub saveToFile {
        my ($self) = @_; # ссылка на объект
        my $fileName = $self->{file};
        open(my $fileHandle, '>', $fileName) or die("Error while opening file $fileName: $!\n"); # открываем файл для перезаписи
        print $fileHandle $self->get();
        close($fileHandle);
    }

    sub addLine {
        my ($self) = @_; # ссылка на объект
        my ($columnsRef, $linesRef) = ($self->{columns}, $self->{lines});
        my $columnCount = scalar(@$columnsRef);
        my %newValues;
        for (my $i = 0; $i < $columnCount; $i++) {
            print(${$columnsRef}[$i] . ": ");
            my $inputValue = <>;
            chomp($inputValue);
            $newValues{${$columnsRef}[$i]} = $inputValue;
        }
        push(@$linesRef, \%newValues);
    }

    sub deleteLine {
        my ($self) = shift; # ссылка на объект
        my $idToSearch = shift; # id переданное в параметре
        my $indexOfLineToDelete = $self->getLineIndexById($idToSearch);
        if ($indexOfLineToDelete > -1) {
            splice(@{$self->{lines}}, $indexOfLineToDelete, 1);
        }
        else {
            print("Line with ID $idToSearch not found!\n");
        }
    }

    sub search {
        my ($self) = shift; # ссылка на объект
        my $searchText = shift;
        my ($columnsRef, $linesRef) = ($self->{columns}, $self->{lines});
        my $columnCount = scalar(@$columnsRef);
        my $tableText = '';

        my @foundIndexes = ();
        while (my ($lineIndex, $hash) = each @$linesRef) {
            for (my $i = 0; $i < $columnCount; $i++) {
                my $value = $hash->{${$columnsRef}[$i]};
                if (index($value, $searchText) != -1) {
                    push(@foundIndexes, $lineIndex);
                    last;
                }
            }
        }

        if (scalar(@foundIndexes) > 0) {
            for (my $i = 0; $i < $columnCount; $i++) {
                $tableText .= ${$columnsRef}[$i];
                $tableText .= ($i < $columnCount - 1) ? "\t" : "\n";
            }
            for my $index (@foundIndexes) {
                my $hash = @$linesRef[$index];
                for (my $i = 0; $i < $columnCount; $i++) {
                    my $value = $hash->{${$columnsRef}[$i]};
                    $tableText .= $value;
                    $tableText .= ($i < $columnCount - 1) ? "\t" : "\n";
                }
            }
        }
        return $tableText;
    }

    sub sortByColumn {
        my ($self) = shift; # ссылка на объект
        my $sortColumnNumber = shift;
        my $sortColumnArrayIndex = $sortColumnNumber-1;
        my ($columnsRef, $linesRef) = ($self->{columns}, $self->{lines});

        my %lineIndexByColumnValue;
        while (my ($lineIndex, $hash) = each @$linesRef) {
            my $value = $hash->{${$columnsRef}[$sortColumnArrayIndex]};
            $lineIndexByColumnValue{$value} = $lineIndex;
        }

        my @sortedLinesIndexes = ();
        my @sortedValues = ();
        try {
            @sortedValues = (sort {lc($a) <=> lc($b)} keys %lineIndexByColumnValue)
        }
        catch {
            @sortedValues = (sort {lc($a) cmp lc($b)} keys %lineIndexByColumnValue);
        };
        foreach my $columnValue (@sortedValues) {
            push(@sortedLinesIndexes, $lineIndexByColumnValue{$columnValue});
        }

        my @sortedLines = ();
        for my $index (@sortedLinesIndexes) {
            push(@sortedLines, @$linesRef[$index]);
        }
        $self->{lines} = \@sortedLines;
    }

    sub getLineIndexById {
        my ($self) = shift; # ссылка на объект
        my $linesRef = $self->{lines};
        my $idToSearch = shift;
        my $index = -1;
        for my $hash (@$linesRef) {
            if ($hash->{ID} eq $idToSearch) {
                $index = $hash->{ID};
                last;
            }
        }
        return $index;
    }

    sub load {
        my ($self) = @_; # ссылка на объект
        my $fileName = $self->{file};
        open(my $fileHandle, '<', $fileName) or die("Error while opening file $fileName: $!\n"); # открываем файл для чтения с начала

        my $firstLine = <$fileHandle>;
        chomp($firstLine);
        my @columns = split("\t", $firstLine);
        my $tableColumnsCount = scalar(@columns);
        my @lines = ();

        while (my $line = <$fileHandle>) {
            my @cells = split("\t", $line);
            my %tableLineHash;
            for (my $i = 0; $i < $tableColumnsCount; $i++) {
                if ($cells[$i]) {
                    chomp($cells[$i]);
                    $tableLineHash{$columns[$i]} = $cells[$i];
                }
                else {
                    $tableLineHash{$columns[$i]} = "-";
                }
            }
            push(@lines, \%tableLineHash);
        }
        close($fileHandle);

        $self->{columns} = \@columns;
        $self->{lines} = \@lines;
    }

    sub get {
        my $tableText = '';
        my ($self) = @_; # ссылка на объект
        my ($columnsRef, $linesRef) = ($self->{columns}, $self->{lines});
        my $columnCount = scalar(@$columnsRef);

        for (my $i = 0; $i < $columnCount; $i++) {
            $tableText .= ${$columnsRef}[$i];
            $tableText .= ($i < $columnCount - 1) ? "\t" : "\n";
        }
        for my $hash (@$linesRef) {
            for (my $i = 0; $i < $columnCount; $i++) {
                my $value = $hash->{${$columnsRef}[$i]};
                $tableText .= $value;
                $tableText .= ($i < $columnCount - 1) ? "\t" : "\n";
            }
        }
        return $tableText;
    }
}

1;
