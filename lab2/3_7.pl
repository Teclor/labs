fib_sum_even(N, R):-
    fib(N, L),
    fseven(L,R).
fseven([H|T],R):-
    fseven(T, R1),
    M is H mod 2,
   (M == 0 -> R is R1 + H; R is R1).
fseven([],0).



%� �����������
fib_sum_odd(N, R):-
    fib(N, L),
    fsodd(L,R, 0).
fsodd([],R,RT):- RT \= 0, R is RT.
fsodd([H|T],R, RT):-
    M is H mod 2,
    (
     M == 1 ->
     RT1 is RT + H;
     RT1 is RT
    ),
    fsodd(T, R, RT1).
