val l1 = [1, 2, 3];
val l2 = 1::2::3::nil;
(* `a :: `a list *)
(* 1::2 error ! *)
l1 = l2;
