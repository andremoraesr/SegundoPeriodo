domeio :: Integer -> Integer -> Integer -> Integer
domeio m n p
    | (m <= p && m >= n) || (m <= n && m >= p)  = m
    | (n <= p && n >= m) || (n <= m && n >= p) = n
    | otherwise = p

entre :: Integer -> Integer -> Integer -> Bool
entre m n p = 
    let alfa = domeio m n p in
        alfa == n