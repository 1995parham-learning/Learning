%%%
%%% In The Name Of God
%%% ========================================
%%% [] File Name : sum.erl
%%%
%%% [] Creation Date : 22-09-2017
%%%
%%% [] Created By : Parham Alvani <parham.alvani@gmail.com>
%%% =======================================
%%%
%%% #######################################
%%%
%%% Copyright (c)  2017 Parham Alvani.
%%%
-module(sum).
-export([sum/1]).

sum([]) ->
	ok;
sum(List) ->
	[Head | Tail] = List,
	io:format("~w~n", [Head]),
	sum(Tail).
