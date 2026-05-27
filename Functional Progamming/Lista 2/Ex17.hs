decaimento :: Double->(Double, Double, (Int, Int, Int))
decaimento mi =
    if mi <= 0.5 then (mi, mi, (0,0,0))
    else sec mi mi 0
    where 
        sec :: Double->Double->Int->(Double, Double, (Int, Int, Int))
        sec mi m t
            | m < 0.5 = (mi, m, (h, min, s))
            | otherwise = sec mi (m/2) (t+50)
                where
                    h = t `div` 3600
                    min = (t `mod` 3600) `div` 60
                    s = t `mod` 60