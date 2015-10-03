(*
 * In The Name Of God
 * ========================================
 * [] File Name : pass-by-ref.sml
 *
 * [] Creation Date : 04-10-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*)
(*
 * Copyright (c) 2015 Parham Alvani.
*)
fun f(x : int ref) = (x := !x + 1; !x);
val y = ref 10;
f(y);
!y;
