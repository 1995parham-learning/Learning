(*
 * In The Name Of God
 * ========================================
 * [] File Name : swap.sml
 *
 * [] Creation Date : 04-10-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*)
(*
 * Copyright (c) 2015 Parham Alvani.
*)
fun swap(x, y) = let val tmp = x in x := !y; y := !tmp end;
