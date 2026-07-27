{-main :: IO ()
main = do
    putStrLn "Digite uma palavra: "
    palavra <- getLine
    if palavra == reverse palavra then putStrLn "E palindromo"
                                    else putStrLn "Nao e palindromo"-}

{-main :: IO ()
main = do
    putStr "Digite um numero: "
    n1 <- readLn :: IO Float
    putStr "Digite outro numero: "
    n2 <- readLn :: IO Float
    putStr "Digite outro numero: "
    n3 <- readLn :: IO Float
    putStrLn ("Produto dos numeros: " ++ show(n1*n2*n3))-}

{-main :: IO ()
main = do
    putStrLn "Nota 1: "
    n1 <- readLn :: IO Double
    putStrLn "Nota 2: "
    n2 <- readLn :: IO Double
    putStrLn "Nota 3: "
    n3 <- readLn :: IO Double
    let media = (n1+n2+n3)/3
    putStrLn ("Media do aluno: " ++ show media)
    putStr "Situacao: "
    if media < 30 then putStrLn "Reprovado."
    else if media < 60 then putStrLn "Substitutiva."
    else putStrLn "Aprovado."-}

import System.IO(stdout, hSetBuffering, BufferMode(NoBuffering))

raizes2grau a b c
    | d > 0 = [(-b + sqrt d)/(2*a), (-b -sqrt d)/2*a]
    | d == 0 = [-b/(2*a)]
    | d < 0 = []
    where
        d = (b)^2 - 4*a*c

main :: IO ()
main = do 
    hSetBuffering stdout NoBuffering
    putStrLn "Coeficiente a = "
    a <- readLn
    putStrLn "Coeficiente b = "
    b <- readLn
    putStrLn "Coeficiente c = "
    c <- readLn
    case raizes2grau a b c of
        [x1, x2] -> putStrLn ("Raizes da equacao: " ++ show x1 ++ " e " ++ show x2)
        [x1]     -> putStrLn ("Raiz: " ++ show x1)
        []       -> putStrLn ("Nao ha raizes nesta equacao.")

