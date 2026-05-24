date :: Int->Int->Int->Bool
date dia mes ano
    | ano < 1 = False
    | mes < 1 || mes > 12 = False
    | dia < 1 || dia > dianomes mes ano = False
    |otherwise = True

dianomes :: Int->Int->Int
dianomes mes ano
    | mes==2   = if bissexto ano then 29 else 28
    | mes `elem` [4, 6, 9, 11]  = 30
    | otherwise = 31

bissexto :: Int->Bool
bissexto ano = (ano `mod` 4 == 0 && ano `mod` 100 /= 0) || (ano `mod` 400 == 0)
