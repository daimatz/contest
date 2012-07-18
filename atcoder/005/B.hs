import System.IO

main = do l1 <- getLine
          let ls = words l1
              x = (read $ ls !! 0) :: Int
              y = (read $ ls !! 1) :: Int
              w = ls !! 2
          maze <- getInput 9
          putStrLn $ str 4 maze (y-1) (x-1) w

getInput :: Int -> IO [String]
getInput 0 = return []
getInput n = do x <- getLine
                y <- getInput (n-1)
                return $ x : y

str :: Int -> [String] -> Int -> Int -> String -> String
str 0 _ _ _ _ = ""

str n maze 0 0 "LU" = maze !! 0 !! 0 : str (n-1) maze 1 1 "RD"
str n maze 0 8 "RU" = maze !! 0 !! 8 : str (n-1) maze 1 7 "LD"
str n maze 8 0 "LD" = maze !! 8 !! 0 : str (n-1) maze 7 1 "RU"
str n maze 8 8 "RD" = maze !! 8 !! 8 : str (n-1) maze 7 7 "LU"

str n maze y 0 "LU" = maze !! y !! 0 : str (n-1) maze (y-1) 1 "RU"
str n maze y 0 "LD" = maze !! y !! 0 : str (n-1) maze (y+1) 1 "RD"
str n maze y 8 "RU" = maze !! y !! 8 : str (n-1) maze (y-1) 7 "LU"
str n maze y 8 "RD" = maze !! y !! 8 : str (n-1) maze (y+1) 7 "LD"

str n maze 0 x "LU" = maze !! 0 !! x : str (n-1) maze 1 (x-1) "LD"
str n maze 0 x "RU" = maze !! 0 !! x : str (n-1) maze 1 (x+1) "RD"
str n maze 8 x "LD" = maze !! 8 !! x : str (n-1) maze 7 (x-1) "LU"
str n maze 8 x "RD" = maze !! 8 !! x : str (n-1) maze 7 (x+1) "RU"

str n maze y 0 "L"  = maze !! y !! 0 : str (n-1) maze y 1 "R"
str n maze y 8 "R"  = maze !! y !! 8 : str (n-1) maze y 7 "L"
str n maze 0 x "U"  = maze !! 0 !! x : str (n-1) maze 1 x "D"
str n maze 8 x "D"  = maze !! 8 !! x : str (n-1) maze 7 x "U"

str n maze y x "L"  = maze !! y !! x : str (n-1) maze y (x-1) "L"
str n maze y x "R"  = maze !! y !! x : str (n-1) maze y (x+1) "R"
str n maze y x "D"  = maze !! y !! x : str (n-1) maze (y+1) x "D"
str n maze y x "U"  = maze !! y !! x : str (n-1) maze (y-1) x "U"

str n maze y x "LU" = maze !! y !! x : str (n-1) maze (y-1) (x-1) "LU"
str n maze y x "RU" = maze !! y !! x : str (n-1) maze (y-1) (x+1) "RU"
str n maze y x "LD" = maze !! y !! x : str (n-1) maze (y+1) (x-1) "LD"
str n maze y x "RD" = maze !! y !! x : str (n-1) maze (y+1) (x+1) "RD"

str n maze y x w = "UNKNOWN ERROR"
