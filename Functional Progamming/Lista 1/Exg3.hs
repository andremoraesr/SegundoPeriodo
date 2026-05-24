char2num :: Char -> Int
char2num a
    | a >= '0' && a <= '9' = fromEnum a - 48
    | otherwise = 0