likes('Ellen',tennis).
likes('John',football).
likes('Tom',baseball).
likes('Tom',swimming).
likes('Mark',tennis).
likes('Bill',X):-likes('Tom',X).
likes('Ellen',reading).
likes('Mark',computers).
likes('John',badminton).
likes('Tom',reading).
is_a(badminton,sport).
is_a(tennis,sport).
is_a(football,sport).
is_a(baseball,sport).
is_a(X,sportsman):-likes(X,Y), is_a(Y,sport).
