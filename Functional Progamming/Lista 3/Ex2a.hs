prodMn :: Int -> Int -> Int
prodMn x y 
    | (x <= 0) || (y <= 0) =  0
    | x == y = x*y
    | x > y  = (x*y)*prodMn (x-1) y
    | otherwise = (x*y)*prodMn x (y-1)