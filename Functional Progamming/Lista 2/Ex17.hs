decaimento :: Double->Int->(Double, Double, (Int, Int, Int))
decaimento mi mv =
    if mi <= 0.5 then (mi, mi, (0,0,0))
    else sec mi mi mv 0
    where 
        sec :: Double->Double->Int->Int->(Double, Double, (Int, Int, Int))
        sec mi m mv t
            | m < 0.5 = (mi, m, (h, min, s))
            | otherwise = sec mi (m/2) mv (t+mv)
                where
                    h = t `div` 3600
                    min = (t `mod` 3600) `div` 60
                    s = t `mod` 60