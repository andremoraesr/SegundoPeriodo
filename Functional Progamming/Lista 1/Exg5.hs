mediaTres :: Integer -> Integer -> Integer -> Double
mediaTres a b c = fromIntegral (a+b+c) / 3.0

quantos :: Integer -> Integer -> Integer -> Integer
quantos a b c =
    (if (fromIntegral a>mediaTres a b c) then 1 else 0) +
    (if (fromIntegral b>mediaTres a b c) then 1 else 0) +
    (if (fromIntegral c>mediaTres a b c) then 1 else 0)