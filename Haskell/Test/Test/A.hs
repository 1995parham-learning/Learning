module Test.A where

firstOfEmpty :: [[Char]] -> [Char]
firstOfEmpty lst = if not (null lst) then head lst else "empty"

lst1 +++ lst2 = if null lst1
		then lst2
		else (head lst1) : (tail lst1 +++ lst2)
reverse lst = if null (tail lst)
              then lst
	      else (Test.A.reverse (tail lst)) ++ ((head lst) : [])
unzip :: [(a, b)] -> ([a], [b])
unzip [] = ([], []) 
unzip ((x, y) : zs) = let (fzs, szs) = Test.A.unzip zs
                      in (x : fzs, y : szs)
