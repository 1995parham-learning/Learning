(*
 * In The Name Of God
 * ========================================
 * [] File Name : pass-by-value-result.sml
 *
 * [] Creation Date : 03-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*)
(*
 * Copyright (c) 2016 Parham Alvani.
*)
val x = ref 0;
fun p(y : int ref) = let
    val yy = !y;
    val yy = 10;
  in
    x := 0;
    y := yy
  end;
p(x);
!x;
