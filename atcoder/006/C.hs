import Control.Applicative ((<$>))
import Control.Monad.State
import Data.List

main = do
  n <- read <$> getLine
  ws <- replicateM n $ read <$> getLine
  print $ solve ws

solve :: [Integer] -> Int
solve ws = length $ snd $ runState (foldl1 (>>) $ map pile ws) []

pile :: Integer -> State [Integer] ()
pile new = state $ \ws -> ((), sort $ f new ws)
    where
      f n [] = [n]
      f n (w:ws) | n <= w    = n:ws
                 | otherwise = w:(f n ws)
