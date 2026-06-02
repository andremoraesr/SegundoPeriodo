separaEles :: String -> (String, String)
separaEles []=([], [])
separaEles (x:xs)
    | x >= '0' && x <= '9'     = (letras, x:numeros)
    | x >= 'a' && x <= 'z'     = (x:letras, numeros)
    | x >= 'A' && x <= 'Z'     = (x:letras, numeros)
    | otherwise    = (letras, numeros)
    where
        (letras, numeros) = separaEles xs