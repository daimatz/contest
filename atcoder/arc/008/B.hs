import Control.Applicative ((<$>))
import System.IO.Unsafe
import Data.List

(n,m,name,kit) = unsafePerformIO getInput

getInput :: IO (Int,Int,String,String)
getInput = do
  [_n,_m] <- map read <$> words <$> getLine
  _name <- getLine
  _kit <- getLine
  return (_n,_m,_name,_kit)

main = do
  print $ solve

solve :: Int
solve = if any (== Nothing) $ map (\x -> elemIndex x kit) name
        then -1
        else let gs = gather kit
             in maximum $ map (\(x, y) -> ceiling $ fromIntegral (length (elemIndices x name)) / fromIntegral y) gs

gather :: Eq a => [a] -> [(a,Int)]
gather xs = map (\(x, y) -> (x, length y)) $ nub $ map (\x -> (x, elemIndices x xs)) xs
