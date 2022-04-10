fib(0, [0]).
fib(1, [1,0]).
fib(N, [R,X,Y|Zs]) :-
    N > 1,
    N1 is N - 1,
    fib(N1, [X,Y|Zs]),
    R is X + Y.

fib_accum(
fib_accum(0, [0]).
fib_accum(1, [1,0]).
fib_accum(N, [R,X,Y|Zs]) :-
    N > 1,
    N1 is N - 1,
    R1 = X+Y,
    fib(N1, [X,Y|Zs]),
    R is X + Y.
