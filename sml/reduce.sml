(*
 * In The Name Of God
 * ========================================
 * [] File Name : reduce.sml
 *
 * [] Creation Date : 04-10-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*)
(*
 * Copyright (c) 2015 Parham Alvani.
*)
datatype 'a tree = LEAF of 'a |
                   NODE of ('a tree * 'a tree);

fun reduce(f) = let
    fun apply(f, NODE(x, y)) = f(apply(f, x), apply(f, y))
    | apply(f, LEAF(x)) = x;
  in
    fn (x) => apply(f, x)
  end;

fun f(x, y) = x + y;
reduce f(NODE(NODE(LEAF 1, LEAF 2), LEAF 3));
