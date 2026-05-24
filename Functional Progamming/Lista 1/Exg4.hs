romanos :: [(Int, String)]
romanos = [ (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"), (100, "C"), (90, "XC"), (50, "L"),
            (40, "XL"), (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I") ]

fazromano :: Int->String
fazromano n =
    if n==0 then ""
    else if n<0 then error "Numeros romanos nao aceitam negativos"
    else 
        letra ++ fazromano(n - valor)
   where
    ((valor, letra) : _)= [(v,l) | (v,l) <- romanos, v<=n]