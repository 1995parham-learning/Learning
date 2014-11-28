module Fib.Fib where

fib :: Integer -> Integer
fib n = case n of
	0 -> 1
	1 -> 1
	_ -> fib (n-1) + fib (n-2)
