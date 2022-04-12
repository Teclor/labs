check_is_sum(NUM, MAXN, N):- check_is_s(NUM, MAXN, 0, N).

check_is_s(NUM, MAXN, TMPN, N):-
    TMPN < MAXN,
    (
     (
      fib_sum_odd(TMPN, S),
      S == NUM
     )
     ->
     (
      N is TMPN, write('ODD')
     );
     (
      fib_sum_even(TMPN, S),
      S == NUM
      )
      ->
      (
       N is TMPN, write('EVEN')
      );
    TMPN1 is TMPN + 1,
    check_is_s(NUM, MAXN, TMPN1, N)
    ).
