factorial(N,FactN):- fact(N,FactN,1,1).
fact(N,FactN,I,P):- /* накопитель I - аналог счетчика */
I<N, /* накопитель P – промежуточное значение факториала*/
I1 is I+1, /*FactN - значение факториала */
P1 is P*I1,
fact(N,FactN,I1,P1).
fact(N,FactN,N,FactN).
