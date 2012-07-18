import System.IO
import Data.List

main = do l1 <- getLine
          l2 <- getLine
          let l = words l1
              n = read $ l !! 0
              k = read $ l !! 1
              lst = map read $ words l2
          calc n k lst

calc :: Int -> Int -> [Int] -> IO ()
calc n k lst = putStrLn $ show $ length $ filter (>= (max 1 (lst !! (k-1)))) lst
