diferentes :: Eq a => [a]-> Bool                                      -- Ex9
diferentes [] = True
diferentes (x:xs) = not (x `elem` xs) && diferentes xs

negativos :: (Num a, Ord a) => [a] -> [a]                            -- Ex11
negativos = filter (<0)

produto :: Num a => [a] -> a                                         -- Ex 16
produto = foldl (*) 1

prefixo :: Eq a => [a]->[a]->Bool                                    -- Ex 21
prefixo [] _ = True
prefixo _ [] = False
prefixo (x:xs) (y:ys) = (x == y) && prefixo xs ys

sup :: (Fractional a, Ord a) => [a]->[a]                                    -- Ex 25
sup a = (\media -> filter (> media) a) (sum a / fromIntegral(length a))

pertencentes :: String -> String -> [String]                                  -- Ex 23
pertencentes termo arq = filter (\linha -> termo `contem` linha) (lines arq)

contem :: Eq a => [a] -> [a] -> Bool
contem _ [] = False
contem a b = ePrefixo a b || contem a (drop 1 b)

ePrefixo :: Eq a => [a]->[a]->Bool
ePrefixo [] _ = True
ePrefixo _ [] = False
ePrefixo (x:xs) (y:ys) = (x == y) && ePrefixo xs ys

tema :: String -> (String, String)                                       -- Ex 28
tema verbo = (take (length verbo -2) verbo, take 1 (drop (length verbo - 2) verbo))

replique :: [a] -> Int->  [a]                                            -- 35
replique [] _ = []
replique (x:xs) n = replicate n x ++ replique xs n
