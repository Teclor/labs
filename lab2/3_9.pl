akkerman_f(0,Y,Y+1).
akkerman_f(X,Y,A):-
    X>0,
    Y=0,
    X1 is X - 1,
    akkerman_f(X1,1,A1),
    A is A1.
akkerman_f(X,Y,A):-
    X>0,
    Y>0,
    Y1 is Y-1,
    X1 is X - 1,
    akkerman_f(X,Y1,A1),
    akkerman_f(X1,A1,A2),
    A is A2.
