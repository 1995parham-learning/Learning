fun f(x : int ref) = (x := !x + 1; !x);
val y = ref 10;
f(y);
!y;
