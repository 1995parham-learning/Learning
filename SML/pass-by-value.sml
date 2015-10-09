fun f(z : int) = let val x = ref z in x := !x + 1; !x end;
