detecta :: Eq a =>[a]->Bool
detecta [] = True
detecta [_]= True 
detecta (x:y:xs) = if x==y
                        then False
                        else detecta (y:xs)