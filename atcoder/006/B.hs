import System.IO
import Control.Applicative ((<$>))
import Data.List
import Control.Monad

main = do
  [n,l] <- map read <$> words <$> getLine
  mp <- replicateM l getLine
  g <- getLine
  let Just g' = elemIndex 'o' g
      g'' = g' `div` 2 + 1
  print $ if n == 1 then 1 else goal n g'' $ reverse mp

goal :: Int -> Int -> [String] -> Int
goal _ c [] = c
goal n c (m:ms) | c <= 1    = if (m !! (2*c-1)) == '-' then goal n (c+1) ms else goal n c ms
                | c >= n    = if (m !! (2*c-3)) == '-' then goal n (c-1) ms else goal n c ms
                | otherwise = if (m !! (2*c-1)) == '-'
                              then goal n (c+1) ms
                              else if (m !! (2*c-3)) == '-'
                                   then goal n (c-1) ms
                                   else goal n c ms
