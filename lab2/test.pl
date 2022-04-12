fibonacci1(1,1,1).
fibonacci1(2,1,2).
fibonacci1(N,F,S):-fibo1(N,F,S,2,1,1,2).
fibo1(N,F,S,I,P1,P2,SP):-
I<N,
I1 is I+1,
P1new is P2,
P2new is P2+P1,
Check is P2new mod 2,
SP1 is SP + (Check*P2new),
fibo1(N,F,S,I1,P1new,P2new,SP1).
fibo1(N,F,S,N,P1,F,S).


fibonacci2(1,1,0).
fibonacci2(2,1,0).
fibonacci2(N,F,S):-fibo2(N,F,S,2,1,1,0).
fibo2(N,F,S,I,P1,P2,SP):-
I<N,
I1 is I+1,
P1new is P2,
P2new is P2+P1,
Check is abs((P2new mod 2)-1),
SP1 is SP + (Check*P2new),
fibo2(N,F,S,I1,P1new,P2new,SP1).
fibo2(N,F,S,N,P1,F,S).
