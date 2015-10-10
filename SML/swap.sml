fun swap(x, y) = let val tmp = x in x := !y; y := !tmp end;
