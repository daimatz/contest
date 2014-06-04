import System.Environment
import Control.Applicative ((<$>))
import Control.Monad
import Data.List

main = do
  b <- concat <$> words <$> getLine
  n <- (read :: String -> Int) <$> getLine
  a <- replicateM n getLine
  putStrLn $ init $ unlines $ map snd $ sort $ map (f 0) $ map (\s -> (map (\c -> elemIndex c b) s, s)) a
      where
        f acc ([], ss) = (acc, ss)
        f acc ((Just k : ks), ss) = f (acc * 10 + k) (ks, ss)
