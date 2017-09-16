%%%
%%% In The Name Of God
%%% ========================================
%%% [] File Name : area.erl
%%%
%%% [] Creation Date : 16-09-2017
%%%
%%% [] Created By : Parham Alvani <parham.alvani@gmail.com>
%%% =======================================
%%%
%%% #######################################
%%%
%%% Copyright (c)  2017 Parham Alvani.
%%%
-module(area).
-export([area/1]).

area({circle, Radius}) ->
	Radius * Radius * math:pi();
area({square, Side}) ->
	Side * Side;
area({rectangle, Height, Width}) ->
	Height * Width.
