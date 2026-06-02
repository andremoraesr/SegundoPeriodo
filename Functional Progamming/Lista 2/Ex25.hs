radical :: String->(String, String)
radical (x:y:xs)
    | length (y:xs) < 3   = ([x],[y])
    | otherwise = (x:radicalresto, vogal)
    where
        (radicalresto, vogal) = radical(y:xs) 