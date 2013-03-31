import Control.Monad
import Data.List

comp1 a b
    | fst a < fst b = LT
    | fst a > fst b = GT
    | snd a < snd b = GT
    | otherwise = LT

comp2 a b
    | snd a > snd b = GT
    | otherwise = LT


addId :: [Int] -> Int -> [(Int, Int)]
addId [] idx = []
addId (cur:rest) idx = (cur, idx):addId rest (idx + 1)

solve :: [(Int, Int)] -> Int -> Int -> [(Int, Int)]
solve [] _ _ = []
solve (pref:suff) cnt k
    | suff == [] && cnt >= k = [pref]
    | suff == [] = []
    | fst pref == fst (suff!!0) = solve suff (cnt + 1) k
    | cnt >= k = pref:solve suff 1 k
    | otherwise = solve suff 1 k
    
main = do
    s <- getLine
    let t = read s :: Int
    forM [1..t] $ \_ -> do
        s <- getLine
        let [n, k] = map read $ words s
        s <- getLine
        let nums = sortBy comp1 (addId (map read $ words s) 0)
        let res = sortBy comp2 (solve nums 1 k)
        putStrLn $ if (res == []) then "-1" else intercalate " " [show x | (x, _) <- res]
