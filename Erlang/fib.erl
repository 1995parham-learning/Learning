%%%
%%% In The Name Of God
%%% ========================================
%%% [] File Name : fib.erl
%%%
%%% [] Creation Date : 21-09-2017
%%%
%%% [] Created By : Parham Alvani <parham.alvani@gmail.com>
%%% =======================================
%%%
%%% #######################################
%%%
%%% Copyright (c)  2017 Parham Alvani.
%%%
-module(fib).
-export([fib/1]).

fib(N) when N =:= 0 ->
	1;
fib(N) when N =:= 1 ->
	1;
fib(N) ->
	fib(N - 1) + fib(N - 2).
