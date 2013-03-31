import Control.Monad

main = do
    s <- getLine
    let t = read s :: Int
    forM [1..t] $ \_ -> do
        s <- getLine
        let n = read s :: Int
        print ((3 * n * (n + 1)) `div` 2 - 2 * n)
