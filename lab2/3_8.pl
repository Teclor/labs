fib2(N, FIB):-fib2(N, FIB, 1, 1, 0).
fib2(N, FIB, I, PR1, PR2):-
    I<N,
    I1 is I+1,
    FIB1 is PR1+PR2,
    fib2(N, FIB, I1, FIB1, PR1).
fib2(N, FIB, N, FIB, _).
chet(X):-F is X mod 2, F == 0.
sum_chet(N, A):-sum_chet(N, A, 0, 0).
sum_chet(N, A, I, SUM):-
    I<N,
    I1 is I + 1,
        fib2(I1, FIBNUM),
    ( chet(FIBNUM) -> SUM1 is SUM + FIBNUM ; SUM1 is SUM ),
    sum_chet(N, A, I1, SUM1).
sum_chet(N, A, N, A).
check_num1(NUM, N):-check_num1(NUM, N, 0, 0).
check_num1(NUM, N, ANS, I):-
    ANS =< NUM,
    I1 is I+1,
    sum_chet(I1, ANS1),
    ( ANS1 == NUM -> ANS2 is NUM+1,
    write('Yep, this is a sum of EVEN Fibonacci numbers!'); ANS2 is ANS1 ),
    check_num1(NUM, N, ANS2, I1).
check_num1(_, N, _, N).
