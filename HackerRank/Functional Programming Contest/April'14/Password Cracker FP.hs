import Control.Monad

getCur :: Int -> [String] -> String -> [Int] -> [Int]
getCur x a b res
        | x == length a = []
        | otherwise = (idx : getCur (x + 1) a b res)
        where {
            idx = (if (take lc b == c) then (if res!!(lc - 1) /= -1 then x else -1) else -1);
            c = a!!x;
            lc = length c;
        }
        

solve :: [String] -> String -> [Int]
solve a [] = [-2]
solve a b = ((maximum cur):res)
    where {
        res = solve a (tail b);
        cur = getCur 0 a b res
    }
    
restore :: [String] -> [Int] -> [String]
restore a (b:bs)
    | b < 0 = []
    | otherwise = c:" ":restore a (drop (length c - 1) bs)
    where c = a!!b

main = do
    s <- getLine
    let tt = read s :: Int
    forM [1..tt] $ \_ -> do
        s <- getLine
        s <- getLine
        let xs = words s
        s <- getLine
        let ys = solve xs s
        putStrLn $ (if (head ys) /= -1 then (concat (restore xs ys)) else "WRONG PASSWORD")
