mdc :: Int->Int->Int
mdc a 0 = abs a
mdc a b = mdc b (a `rem` b)

mmc :: Int->Int->Int
mmc 0 0 = 0
mmc a b = (a*b) `div` mdc a b

mmc3 :: Int->Int->Int->Int
mmc3 a b c = mmc (mmc a b) c