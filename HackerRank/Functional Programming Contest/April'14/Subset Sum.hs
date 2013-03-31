import Control.Monad
import Data.List

get [] _ _ = []
get (a:as) [] x = (snd a, -1):get as [] (x + 1)
get (a:as) (b:bs) x
    | fst a <= b = (snd a, x):get as (b:bs) x
    | otherwise = get (a:as) bs (x + 1)

psum [] _ = []
psum (x:xs) s = (s+x):psum xs (s + x)

comp a b
    | a < b = GT
    | otherwise = LT

main = do
    s <- getLine
    s <- getLine
    let xs = map read $ words s
    s <- getLine
    let [t] = map read $ words s
    let ys = psum (sortBy comp xs) 0
    qs <- forM [0..t-1] $ \i -> do
        s <- getLine
        let [x] = map read $ words s
        return (x, i)
    let qs1 = sort qs
    let qs2 = sort (get qs1 ys 1)
    mapM_ print [x | (_, x) <- qs2]
