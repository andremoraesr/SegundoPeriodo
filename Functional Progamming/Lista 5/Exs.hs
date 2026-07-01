segmentos :: (a->Bool) -> [a] -> [[a]]                                    -- Ex 1
segmentos _ [] = []
segmentos p (x:xs)
    | p x = (x: takeWhile p xs) : segmentos p (dropWhile p xs)
    | otherwise = segmentos p xs


linhas :: String -> [String]                                              --Ex1.a)
linhas = segmentos (/= '\n')


palavras :: String -> [String]                                            --Ex1.b)
palavras = segmentos isSpace
    where isSpace :: Char->Bool
          isSpace carac
            | carac == ' ' = False
            | carac == '\t' = False
            | otherwise = True