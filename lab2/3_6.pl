fib(0, [0]).
fib(1, [1,0]).
fib(N, [R,X,Y|Zs]) :-
    N > 1,
    N1 is N - 1,
    fib(N1, [X,Y|Zs]),
    R is X + Y.

fib_acc(N, R, NC, [X,Y|Zs]) :-
    N > NC,
    N1 is NC + 1,
    T is X + Y,
    fib_acc(N, R, N1, [T,X,Y|Zs]).
fib_acc(N, R, N, R).

fib_accum(N, R):- fib_acc(N, R, 1, [1,0]).


