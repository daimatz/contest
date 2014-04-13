{-# LANGUAGE ScopedTypeVariables #-}

import           Control.Applicative ((<$>))
import           Control.Monad       (forM_, replicateM)

max_x :: Int
max_x = 100000

main :: IO ()
main = do
    (t :: Int) <- read <$> getLine
    (cases :: [(Double, Double, Double)]) <- replicateM t $ do
        [c, f, x] <- map read . words <$> getLine
        return (c, f, x)
    forM_ (zip [1..] cases) $ \(n, cs) ->
        putStrLn $ "Case #" ++ (show n) ++ ": " ++ (show $ solve cs)

solve :: (Double, Double, Double) -> Double
solve (c, f, x) =
    let
        time_n = scanl (\sum n -> sum + c / (2.0 + fromIntegral n * f)) 0.0 [0 .. max_x]
        x_n = map (\(n, t) -> x / (2.0 + fromIntegral n * f) + t) $ zip [0..] time_n
    in
        minimum x_n
