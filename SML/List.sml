(*
 * In The Name Of God
 * ========================================
 * [] File Name : List.sml
 *
 * [] Creation Date : 04-10-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*)
(*
 * Copyright (c) 2015 Parham Alvani.
*)
val l1 = [1, 2, 3];
val l2 = 1::2::3::nil;
(* `a :: `a list *)
(* 1::2 error ! *)
l1 = l2;
