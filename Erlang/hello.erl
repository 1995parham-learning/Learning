%%%
%%% In The Name Of God
%%% ========================================
%%% [] File Name : hello.erl
%%%
%%% [] Creation Date : 14-09-2017
%%%
%%% [] Created By : Parham Alvani <parham.alvani@gmail.com>
%%% =======================================
%%%
%%% #######################################
%%%
%%% Copyright (c)  2017 Parham Alvani.
%%%
-module(hello).
-export([say/0]).

say() ->
	io:format("Hello\n").
