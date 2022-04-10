module Lab_2_1 where

naturalNumbers :: Integer -> [Integer]
naturalNumbers 0 =[]
naturalNumbers n | n > 0 = naturalNumbers(n-1)++[n]
	   | n < 0 = error "argument is less than zero"

naturalOddNumbers :: Integer -> [Integer]
naturalOddNumbers 0 = []
naturalOddNumbers n | n > 0 = naturalOddNumbers(n-1)++[n*2-1]
            | n < 0 = error "argument is less than zero"

naturalEvenNumbers :: Integer -> [Integer]
naturalEvenNumbers 0 = []
naturalEvenNumbers n | n > 0 = naturalEvenNumbers(n-1)++[2*n]
          | n < 0 = error "aargument is less than zero"

squares :: Integer -> [Integer]
squares 0 =[]
squares n | n > 0 = squares(n-1)++[n*n]
           | n < 0 = error "argument is less than zero"

factorials :: Integer -> [Integer]
factorials 0 =[]
factorials n | n > 0 = factorials(n-1)++[factor n]
            | n < 0 = error "argument is less than zero"
	where 
		factor 0 = 1
		factor n = n * factor (n-1)

degreesOfTwo :: Integer -> [Integer]
degreesOfTwo 0 = []
degreesOfTwo n | n > 0 = degreesOfTwo(n-1)++[2^n]
         | n < 0 = error "argument is less than zero"

triangleNumbers 0 = []
triangleNumbers n | n > 0  = triangleNumbers(n-1)++[n*(n+1)*0.5]
           | n < 0 = error "argument is less than zero"

pyramidNumbers 0 = []
pyramidNumbers n| n > 0  = pyramidNumbers(n-1)++[n*(n+1)*(n+2)/6]
            | n < 0 = error "argument is less than zero"

