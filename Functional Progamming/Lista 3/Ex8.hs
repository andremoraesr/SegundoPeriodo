multlistas :: [Int]->[Int]->[[Int]]
multlistas xs ys = map(\x -> map (x*) ys ) xs