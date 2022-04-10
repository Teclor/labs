module Lab_2_2 where

average :: [Double]-> Double
average a = let
    helper sum count [] = sum/count
    helper sum count (h:t) = helper (sum+h) (1.0+count) (t)
    in helper 0 0 a

getElementByNumber :: Integer->[a]->a
getElementByNumber 1 (h:t)= h
getElementByNumber n (h:t)= getElementByNumber (n-1) t

sumLists :: [Int]->[Int]->[Int]
sumLists [] [] = []
sumLists (h1:t1) [] = [h1] ++ sumLists t1 []
sumLists [] (h2:t2) = [h2] ++ sumLists [] t2
sumLists (h1:t1) (h2:t2) = [h1+h2] ++ sumLists t1 t2

swapOddAndEvenIndexes :: [a]->[a]
swapOddAndEvenIndexes [] = []
swapOddAndEvenIndexes (f:s:t) = [s]++[f]++swapOddAndEvenIndexes t
swapOddAndEvenIndexes (f:t) = [f]++swapOddAndEvenIndexes t

twopow :: Int->Int
twopow n | n == 1 = 2
     | even n = twopow (n `div` 2) * twopow (n `div` 2)
     | odd n = 2 * (twopow ((n-1) `div` 2)) * (twopow ((n-1) `div` 2))
     
removeOdd :: [Int]->[Int]
removeOdd [] = []
removeOdd (h:t) | odd h = removeOdd t
        | otherwise = [h] ++ removeOdd t

removeEmpty :: [String] -> [String]
removeEmpty [] = []
removeEmpty (h:t) | isEmptyStr h = removeEmpty t
                  | otherwise = h : removeEmpty t
    where isEmptyStr [] = True
          isEmptyStr _ = False

removeEmpty' [] = []
removeEmpty' ("":t) = removeEmpty' t
removeEmpty' (h:t) = h : removeEmpty' t

countTrue :: [Bool] -> Integer
countTrue a = let
    helper count [] = count
    helper count (h:t) | h==True = helper (1+count) (t)
                       | otherwise = helper (count) (t)
    in helper 0 a

makePositive :: [Integer]->[Integer]
makePositive [] = []
makePositive (h:t) = [abs h]++makePositive(t)

delete :: Char -> String -> String
delete c [] = []
delete c (h:t) | h == c = delete c (t)
           | otherwise = h : delete c (t)

substitute :: Char -> Char -> String -> String
substitute c1 c2 [] = []
substitute c1 c2 (h:t) | h == c1 = c2 : substitute c1 c2 (t)
                   | otherwise = h : substitute c1 c2 (t)