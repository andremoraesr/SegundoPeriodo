fx :: Double->Double
fx x
    | x<=0  =0
    | otherwise = x

er :: Double->Double
er r
    | r<=1      =r
    | otherwise = 1/(r*r)