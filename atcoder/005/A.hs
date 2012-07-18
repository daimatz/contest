import System.IO

main = do n <- (readLn :: IO Int)
          line <- getLine
          print $ length $ filter (`elem` lst ++ map (\ss -> ss ++ ".") lst) $ words line
    where lst = ["TAKAHASHIKUN", "Takahashikun", "takahashikun"]
