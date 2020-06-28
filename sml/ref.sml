(*
 * In The Name Of God
 * ========================================
 * [] File Name : ref.sml
 *
 * [] Creation Date : 04-10-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*)
(*
 * Copyright (c) 2015 Parham Alvani.
*)
val x = ref 0;
x := 3 * (!x) + 5;
x;
