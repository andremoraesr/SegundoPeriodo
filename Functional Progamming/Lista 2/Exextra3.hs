conta :: Eq a => a->[a]->Int
conta _ [] = 0
conta a (x:xs)
    | a == x = 1 + conta a xs
    | otherwise = conta a xs