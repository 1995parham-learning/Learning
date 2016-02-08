(*
 * In The Name Of God
 * ========================================
 * [] File Name : Lisp-Like.sml
 *
 * [] Creation Date : 04-10-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*)
(*
 * Copyright (c) 2015 Parham Alvani.
*)
datatype LISP = Nil
              | Symbol of string
              | Number of int
              | Cons of LISP * LISP
              | Function of (LISP -> LISP);

fun atom(Symbol s) = Symbol("T")
    | atom(Nil) = Symbol("T")
    | atom(Number n) = Symbol("T")
    | atom(Function f) = Symbol("T")
    | atom(Cons c) = Nil;

fun islist(Cons c) = islist(#2(c))
    | islist(Nil) = Symbol("T")
    | islist(Symbol s) = Nil
    | islist(Function f) = Nil
    | islist(Number n) = Nil;

fun car(Cons c) = #1(c);

fun f(x) = Cons(x, Symbol("A"));
