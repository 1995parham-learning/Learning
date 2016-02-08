(*
 * In The Name Of God
 * ========================================
 * [] File Name : tail.sml
 *
 * [] Creation Date : 03-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*)
(*
 * Copyright (c) 2016 Parham Alvani.
*)
fun mult(a, b) = let val result = ref 0; val i = ref a in
  while !i > 0 do (
    i := !i - 1;
    result := !result + b);
  !result
  end;

