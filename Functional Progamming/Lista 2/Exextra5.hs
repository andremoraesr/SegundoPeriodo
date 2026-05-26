associa :: [a]->[(Int, a)]
associa x = aux 1 x
    where
        aux :: Int->[a]->[(Int, a)]
        aux _ [] = []
        aux i (x:xs) = (i, x) : aux (i+1) xs