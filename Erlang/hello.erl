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
-export([say/1]).
-export([either_or/2]).

say(Name) ->
	io:format("Hello ~s~n", [Name]).

either_or(true, A) when is_boolean(A) ->
	true;
either_or(A, true) when is_boolean(A) ->
	true;
either_or(false, false) ->
	false.
