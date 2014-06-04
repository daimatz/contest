import System.IO

main = do n <- readLn
          lst <- getInput n
          print $ maximum $ map calc [(p1, p2) | p1 <- lst, p2 <- lst]

getInput :: Int -> IO [(Double, Double)]
getInput 0 = return []
getInput n = do line <- getLine
                let ws = words line
                    x = (read $ ws !! 0) :: Double
                    y = (read $ ws !! 1) :: Double
                lst <- getInput (n-1)
                return $ (x,y):lst

calc :: ((Double, Double), (Double, Double)) -> Double
calc ((x0, y0), (x1, y1)) = sqrt ((x1-x0)**2 + (y1-y0)**2)
