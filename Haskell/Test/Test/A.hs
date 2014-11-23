module Test.A where

firstOfEmpty :: [[Char]] -> [Char]
firstOfEmpty lst = if not (null lst) then head lst else "empty"
