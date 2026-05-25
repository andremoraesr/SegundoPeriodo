maxoc :: Int -> Int -> Int -> (Int, Int)
maxoc x y z = (alfa, n)
    where
        alfa = maior x y z

        n = (if alfa == x then 1 else 0) +
            (if alfa == y then 1 else 0) +
            (if alfa == z then 1 else 0)
        


maior :: Int->Int->Int->Int
maior x y z
    | x > y && x > z  = x
    | y > z = y
    | otherwise = z