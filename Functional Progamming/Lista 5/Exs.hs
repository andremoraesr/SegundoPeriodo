segmentos :: (a->Bool) -> [a] -> [[a]]                                    -- Ex 1
segmentos _ [] = []
segmentos p (x:xs)
    | p x = (x: takeWhile p xs) : segmentos p (dropWhile p xs)
    | otherwise = segmentos p xs


linhas :: String -> [String]                                              --Ex1.a)
linhas = segmentos (/= '\n')


palavras :: String -> [String]                                            --Ex1.b)
palavras = segmentos isSpace
    where isSpace :: Char->Bool
          isSpace carac
            | carac == ' ' = False
            | carac == '\t' = False
            | otherwise = True


takewhile' :: (a->Bool)->[a]->[a]                                        --ExExtra
takewhile' _ [] = []
takewhile' p (x:xs)
    | p x = x : takewhile' p xs
    | otherwise = takewhile' p xs


--Pt.2
--Ex1
type Cidade = String

data ClasseTrem = PrimeiraClasse | SegundaClasse
    deriving(Eq, Show)

data ClasseAviao = Executiva | Economica
    deriving(Eq, Show)

data Bilhete = Trem Cidade Cidade ClasseTrem | Onibus Cidade Cidade | Aviao Cidade Cidade ClasseAviao
    deriving(Eq, Show)

type Viagem = [Bilhete]

origem :: Bilhete -> Cidade
origem (Trem c1 _ _) = c1
origem (Onibus c1 _) = c1
origem (Aviao c1 _ _) = c1

destino :: Bilhete -> Cidade
destino (Trem _ c2 _) = c2
destino (Onibus _ c2) = c2
destino (Aviao _ c2 _) = c2

validaViagem :: Viagem -> Bool
validaViagem [] = True
validaViagem [_] = True
validaViagem (b1:b2:resto) = destino b1 == origem b2 && validaViagem (b2:resto)

--Ex2
data Ctt = Contato String | Fone String
    deriving(Eq, Show)

data Horario = AM Int Int | PM Int Int
    deriving(Eq, Ord)

type Dia = (Int, Int, Int)

data App = Whatsapp | LinkdedIn | Facebook
    deriving(Eq)

type Texto = String

type Mensagem = (Ctt, Texto , Dia, Horario, App)

type Conjunto = [Mensagem]

criarMensagem :: Ctt -> String -> Dia -> Horario -> App -> Mensagem
criarMensagem c texto dia horario app = (c, take 100 texto, dia, horario, app)

minutosDoDia :: Horario -> Int
minutosDoDia (AM h m) = (if h == 12 then 0 else h) * 60 + m
minutosDoDia (PM h m) = (if h == 12 then 12 else h + 12) * 60 + m

chaveData :: Dia -> (Int, Int, Int)
chaveData (dia, mes, ano) = (ano, mes, dia)

extrairData :: Mensagem -> Dia
extrairData (_, _, d, _, _) = d

extrairHorario :: Mensagem -> Horario
extrairHorario (_, _, _, h, _) = h

inserirPorHorario :: Mensagem -> [Mensagem] -> [Mensagem]
inserirPorHorario m [] = [m]
inserirPorHorario m (x:xs)
    | minutosDoDia (extrairHorario m) >= minutosDoDia (extrairHorario x) = m : x : xs
    | otherwise = x : inserirPorHorario m xs

ordenarPorHorario :: [Mensagem] -> [Mensagem]
ordenarPorHorario = foldr inserirPorHorario []

intercalarPorData :: [Mensagem] -> [Mensagem] -> [Mensagem]
intercalarPorData [] ys = ys
intercalarPorData xs [] = xs
intercalarPorData (x:xs) (y:ys)
    | chaveData (extrairData x) >= chaveData (extrairData y) = x : intercalarPorData xs (y:ys)
    | otherwise = y : intercalarPorData (x:xs) ys

ordenarPorData :: [Mensagem] -> [Mensagem]
ordenarPorData []  = []
ordenarPorData [x] = [x]
ordenarPorData xs  =
    let metade = length xs `div` 2
        (esq, dir) = splitAt metade xs
    in intercalarPorData (ordenarPorData esq) (ordenarPorData dir)

ordenarMensagens :: [Mensagem] -> [Mensagem]
ordenarMensagens msgs = ordenarPorData (ordenarPorHorario msgs)

ehDoContato :: String -> Mensagem -> Bool
ehDoContato nomeBusc (Contato nome, _, _, _, _) = nome == nomeBusc
ehDoContato foneBusc (Fone fone, _, _, _, _) = fone == foneBusc

pega2 :: Conjunto -> String -> Conjunto
pega2 msgs contatoBusc = take 2(filter (ehDoContato contatoBusc) msgs)

--Ex3
data Arvore a = Vazia | No (Arvore a) a (Arvore a)
    deriving (Show, Eq)

mapA :: (a->b) -> Arvore a -> Arvore b
mapA _ Vazia = Vazia
mapA f (No esq v dir) = No (mapA f esq) (f v) (mapA f dir)

elemA :: Eq a => a -> Arvore a -> Bool
elemA _ Vazia = False
elemA x (No esq v dir)
    | x == v = True
    | otherwise = elemA x esq || elemA x dir

remover :: Ord a => a -> Arvore a -> Arvore a
remover _ Vazia = Vazia
remover x (No esq v dir)
    | x < v = No (remover x esq) v dir -- procura na esquerda
    | x > v = No esq v (remover x dir) -- procura na direita
    | otherwise = reconstruir esq dir 
    where
        reconstruir Vazia d = d -- caso 2: s´o possui filho `a direita; tamb´em cobre caso 1
        reconstruir e Vazia = e -- caso 2: s´o possui filho `a esquerda
        reconstruir e d =
            let m = menor d -- caso 3: encontra o menor valor na direita
            in No e m (remover m d) -- remove o menor e o recoloca no lugar do n´o original
        menor (No Vazia v _) = v
        menor (No e _ _) = menor e

filterA :: Ord a => (a -> Bool) -> Arvore a -> Arvore a
filterA _ Vazia = Vazia
filterA p (No esq v dir)
    | p v = No esqFiltrada v dirFiltrada
    | otherwise = remover v (No esqFiltrada v dirFiltrada)
    where
        esqFiltrada = filterA p esq
        dirFiltrada = filterA p dir

--Ex6
buscaSegura :: Eq a => a -> [a] -> Maybe Int
buscaSegura x lista = aux 0 lista
    where
        aux _ [] = Nothing
        aux acc (y:ys)
            | x == y = Just acc
            | otherwise = aux (acc+1) ys


--Ex7
data DadosPessoa = DadosPessoa{idade :: Int, nome :: String}
    deriving(Eq, Show, Ord)

validarIdade :: DadosPessoa -> Either String DadosPessoa
validarIdade p
    | idade p < 0 || idade p > 120 =  Left "Idade invalida"
    | otherwise = Right p

--Ex8
data Estudante = Estudante  {matricula :: Int,
                            nomex :: String, notas :: [Double]}
    deriving(Show, Eq)

mediaAprovacao :: Estudante -> Maybe Double
mediaAprovacao (Estudante _ _ n)
    | n == [] = Nothing
    | otherwise = Just (aux n / fromIntegral (length n))
        where
            aux [] = 0.0
            aux (x:xs) = x + aux xs

--Ex9
data Usuario = Usuario {login :: String, senha :: String}
    deriving(Show, Eq)

autenticar :: String -> String -> [Usuario] -> Either String Usuario
autenticar l s u
    | l == [] = Left "Credenciais Invalidas"
    | s == [] = Left "Credenciais Invalidas"
    | otherwise = aux l s u
        where
            aux _ _ [] = Left "Credenciais Invalidas"
            aux log sen (u:us)
                | login u == log && sen == senha u = Right u
                | otherwise = aux log sen us


--Ex10
data Livro = Livro{titulo :: String, autor :: String, emprestado :: Bool}
    deriving(Eq, Show)

emprestarLivro :: Livro -> Maybe Livro
emprestarLivro livro =
    if emprestado livro then Nothing
    else Just livro{emprestado = True}