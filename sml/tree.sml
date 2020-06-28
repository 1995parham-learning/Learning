(*
 * In The Name Of God
 * ========================================
 * [] File Name : tree.sml
 *
 * [] Creation Date : 04-10-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*)
(*
 * Copyright (c) 2015 Parham Alvani.
*)
datatype tree = leaf of int | node of tree * tree;
fun inTree(x, leaf(y)) = x = y
  | inTree(x, node(y, z)) = inTree(x, y) orelse inTree(x, z);
