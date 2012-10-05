import System.IO
import Control.Monad.State

main = do
  l1 <- getLine
  let [n,m] = map (read :: String -> Int) $ words l1
  d <- f m
  -- print $ runState (g 2 >> g 3 >> g 5 >> g 0 >> g 1 >> g 3) (0, [1,2,3,4,5])
  putStrLn $ init $ unlines $ map show $ solve n d
  where
    f 0 = return []
    f m = do
         s <- getLine
         t <- f (m-1)
         return $ (read s :: Int):t

solve :: Int -> [Int] -> [Int]
solve n [] = [1..n]
solve n d = snd $ snd $ runState (foldl1 (>>) $ map g d) (0, [1..n])

g :: Int -> State (Int, [Int]) ()
g new = state $ \(cur, disks) -> ((), (new, h cur disks))
    where
      h _ [] = []
      h c (l:ls) = if l == new
                   then c:ls
                   else l:(h c ls)
