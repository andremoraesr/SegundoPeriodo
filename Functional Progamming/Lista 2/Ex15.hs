seg :: Int->Int->Int->Int
seg h m s 
    | m >59 || m<0 = error"Numero invalido"
    | h<0 = error"Numero invalido"
    | s > 59 || s<0 = error"Numero invalido"
    | otherwise = h*3600 + m*60 + s