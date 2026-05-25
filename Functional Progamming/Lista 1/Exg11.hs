ordena :: (Int,Int,Int) -> (Int,Int,Int)
ordena (x, y, z) = (small, mid, big)
    where
        big = maior (x, y, z)

        mid = domeio (x, y ,z)

        small = menor (x, y, z)


maior :: (Int, Int, Int)->Int
maior (x, y, z)
    | x > y && x > z  = x
    | y > z = y
    | otherwise = z

domeio :: (Int, Int, Int) -> Int
domeio (m, n, p)
    | (m <= p && m >= n) || (m <= n && m >= p)  = m
    | (n <= p && n >= m) || (n <= m && n >= p) = n
    | otherwise = p

menor :: (Int, Int, Int)->Int
menor (x, y, z)
    | x < y && x < z  = x
    | y < z = y
    | otherwise = z