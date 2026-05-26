duplica :: [a]->[a]
duplica []=[]
duplica (x:xs) = [x] ++ [x] ++ duplica xs
