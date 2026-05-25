quantosig :: Integer -> Integer -> Integer -> Integer
quantosig a b c
    | a == b && b ==c = 3
    | a /=b && b /= c && a /= b = 0
    | otherwise = 2