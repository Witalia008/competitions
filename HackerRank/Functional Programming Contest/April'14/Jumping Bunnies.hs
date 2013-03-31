llcm [] = 1
llcm [a] = a
llcm (x:xs) = lcm x (llcm xs)

main :: IO ()
main = do
    s <- getLine
    s <- getLine
    let xs = map read $ words s
    print (llcm xs)
