import Data.Char (toUpper)


idig2intFold :: [Integer] -> Integer                                -- Ex 7.a)
idig2intFold a = foldr (\digito acumulador -> toInteger digito + acumulador*10) 0 a


prodImpares :: [Int]->Int                                          -- Ex 12
prodImpares x = (\impares -> foldr (*) 1 impares) (filter odd x)


maiusculas :: [String]->String                                     -- Ex13
maiusculas x = map toUpper (foldr (\palavra acumulador -> palavra ++ " " ++ acumulador)"" x)


separaNomes :: [String] -> ([String], [String])                    -- Ex 28
separaNomes a = ([takeWhile (/= ' ') x | x <- a], [drop 1 (dropWhile (/= ' ') y) | y <- a])


negativos :: [Int] -> [Int]                                        -- Ex 18
negativos xs = [x | x <- xs, x < 0]


intersecao :: Eq t => [t] -> [t] -> [t]                             -- Ex 19
intersecao xs ys = [x | x <- xs, x `elem` ys]


nsei7 :: (Eq t, Integral t) => [t]->[t]                                          -- Ex 22
nsei7 xs = [x | x <- xs, x `mod` 7 == 3]


distancia :: [(Double, Double)] -> [Double]                            -- Ex 20
distancia lista = [sqrt (x^(2 :: Int) + y^(2 :: Int)) | (x,y) <- lista]


fatorial :: Integral t => t -> [t]                                   -- Ex 23
fatorial num = [product[1..x] | x <- [1..(num-1)]]