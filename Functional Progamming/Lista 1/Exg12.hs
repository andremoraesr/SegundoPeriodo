raiz :: Int->Int->Maybe Double
raiz a b =
    if (a == 0) 
        then Nothing
        else Just x
    where x = fromIntegral (-b)/ fromIntegral a