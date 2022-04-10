fib_sum_even(N, R):-
    fib(N, L),
    fseven(L,R).
fseven([H|T],R):-
    fseven(T, R1),
    M is H mod 2,
   ((M = 0, R is R1 + H); R is R1).
fseven([],0).
fib_sum_odd(N, R):-
    fib(N, L),
    fsodd(L,R).
fsodd([H|T],R):-
    fsodd(T, R1),
    M is H mod 2,
   ((M = 1, R is R1 + H); R is R1).
fsodd([],0).
