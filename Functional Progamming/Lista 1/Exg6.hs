eq :: Double->Double->Double->[Double]
eq a b c
    | a == 0 = error "O coeficiente nao e aceito"
    | delta < 0 = []
    | delta == 0 = [x1]
    |otherwise = [x1, x2]
        where
            delta = b*b -4*a*c
            x1 = (-b + sqrt delta) / 2*a
            x2 = (-b - sqrt delta) / 2*a

conta :: Double->Double->Double->Int
conta a b c = length (eq a b c)

menor :: Double->Double->Double->Double
menor a b c =
    case eq a b c of
        [] -> 0
        [x] -> 0
        [x1, x2] -> if x1<x2 then x1 else x2