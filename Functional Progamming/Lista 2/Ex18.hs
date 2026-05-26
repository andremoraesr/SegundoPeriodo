bissexto :: Int->Bool
bissexto a
    | a `mod` 4 /= 0        = False
    | a `mod` 400 == 0      = True
    | a `mod` 100 == 0      = False
    | otherwise = True