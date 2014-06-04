import System.Environment
import Control.Applicative ((<$>))
import Control.Monad

main = do
  n <- (read :: String -> Int) <$> getLine
  ss <- replicateM n $ map (read :: String -> Int) <$> words <$> getLine
  print $ (solve ss) * 105 `div` 100

solve :: [[Int]] -> Int
solve [] = 0
solve (s:ss) = (s !! 0) * (s !! 1) + solve ss
