maiuscula :: String->String
maiuscula str = [converte c | c <- str]
    where
        converte c
            | c >= 'a' && c <= 'z' = toEnum (fromEnum c - 32)
            |otherwise = c