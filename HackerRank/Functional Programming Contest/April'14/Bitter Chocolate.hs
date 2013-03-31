import Control.Monad
import Data.Bool

nmax = 25

getPos :: [[[Bool]]] -> Int -> Int -> Int -> Bool
getPos matr i j k
    | i < 1 || j < 0 || k < 0 = True
    | otherwise = c
    where {
        a = matr !! (length matr - i);
        b = a !! (length a - j - 1);
        c = b !! (length b - k - 1)
    }

delFst :: [[[Bool]]] -> Int -> Int -> Int -> Bool
delFst matr 0 j k = True
delFst matr i j k = (getPos matr i (min i j) (min i k)) && (delFst matr (i - 1) j k)

delSnd :: [[[Bool]]] -> Int -> Int -> Int -> Bool
delSnd matr i (-1) k = True
delSnd matr i j k = (getPos matr i j (min j k)) && (delSnd matr i (j - 1) k)

delThr :: [[[Bool]]] -> Int -> Int -> Int -> Bool
delThr matr i j (-1) = True
delThr matr i j k = (getPos matr i j k) && (delThr matr i j (k - 1))

calcCell :: [[[Bool]]] -> Int -> Int -> Int -> Bool
calcCell matr i j k
    | i == 1 && j == 0 && k == 0 = False
    | i < j || j < k = True
    | otherwise = not((delFst matr (i - 1) j k) && (delSnd matr i (j - 1) k) && (delThr matr i j (k - 1)))

calc3 :: [[Bool]] -> [[[Bool]]] -> Int -> Int -> Int -> [Bool]
calc3 c2prev c1prev i j (-1) = []
calc3 c2prev c1prev i j k = (calcCell ((c3prev : c2prev) : c1prev) i j k) : c3prev
    where c3prev = calc3 c2prev c1prev i j (k - 1)

calc2 :: [[[Bool]]] -> Int -> Int -> [[Bool]]
calc2 c1prev i (-1) = []
calc2 c1prev i j = (calc3 c2prev c1prev i j nmax) : c2prev
    where c2prev = calc2 c1prev i (j - 1)

calc1 :: Int -> [[[Bool]]]
calc1 0 = []
calc1 i = (calc2 c1prev i nmax) : c1prev
    where c1prev = calc1 (i - 1)

main = do
    let np = calc1 nmax
    --print np
    s <- getLine
    let t = read s :: Int
    forM [1..t] $ \_ -> do
        s <- getLine
        let [row1, row2, row3] = map read $ words s
        putStrLn $ (if (getPos np row1 row2 row3) == True then "WIN" else "LOSE")
