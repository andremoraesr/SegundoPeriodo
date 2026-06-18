retornaSup :: Ord a => a -> [a] -> Int
retornaSup _ [] = 0
retornaSup x (y:ys)
    | x > y = 1 + retornaSup x ys
    | otherwise = retornaSup x ys