(*
 * In The Name Of God
 * ========================================
 * [] File Name : pass-by-value.sml
 *
 * [] Creation Date : 04-10-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*)
(*
 * Copyright (c) 2015 Parham Alvani.
*)
fun f(z : int) = let val x = ref z in x := !x + 1; !x end;
val y = ref 10;
f(!y);
!y;
