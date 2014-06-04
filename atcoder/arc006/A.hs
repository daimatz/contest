import Control.Applicative ((<$>))

main = do
  e <- map read <$> words <$> getLine
  b <- read <$> getLine
  l <- map read <$> words <$> getLine :: IO [Int]
  print $ case length $ [(x,y) | x <- e, y <- l, x == y] of
            6 -> 1 :: Int
            5 -> if b `elem` l then 2 else 3
            4 -> 4
            3 -> 5
            _ -> 0
