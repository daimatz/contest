import Control.Applicative ((<$>))

main = do
  n <- read <$> getLine
  print $ solve n

solve :: Int -> Int
solve n
    | n < 0     = 0
    | n < 7     = n * 15
    | otherwise = 100 + solve (n - 10)
