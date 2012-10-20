{-# LANGUAGE BangPatterns #-}

import Control.Applicative ((<$>))
import Data.List

main = do
  [n,k] <- map (read :: String -> Integer) <$> words <$> getLine
  print $ solve n k

prime = 1777777777

a :: Integer -> Integer
a n = f 3 0 1
    where
      f !i !p !q | i == n+2  = p
                 | otherwise = f (i+1) q $! (i-1) * (p+q) `mod` prime

fact :: Integer -> Integer
fact 1 = 1
fact n = n * fact (n-1) `mod` prime

comb :: Integer -> Integer -> Integer
comb !n !k =
    let x = foldl1' mul [n-k+1..n]
        y = foldl1' mul [1..k]
    in x * inv y `mod` prime

mul :: Integer -> Integer -> Integer
mul n k = n * k `mod` prime

inv :: Integer -> Integer
inv x = pow x (prime-2)
    where
      pow _ 0   = 1
      pow !i !j = let t = (pow i $! j `div` 2) ^ (2 :: Int)
                  in t * (if odd j then i else 1) `mod` prime

solve :: Integer -> Integer -> Integer
solve n k | k == 0    = 1
          | k == 1    = 0
          | otherwise = comb n k * a k `mod` prime
