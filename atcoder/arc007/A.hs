import System.IO

main = do
  x <- getLine
  s <- getLine
  putStrLn $ filter (x !! 0 /=) s
