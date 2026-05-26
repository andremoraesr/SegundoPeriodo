ehprimo :: Int-> Bool
ehprimo n = 
    if n <= 1
        then error "Numero invalido"
        else aux 2
    where
    aux candidato
        | candidato > (n `div` 2) = True
        | n `mod` candidato == 0 = False
        | otherwise = aux (candidato+1)