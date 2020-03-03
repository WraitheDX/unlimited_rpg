# unlimited_rpg

This is a text-based RPG that runs in a console window.
Programmed for Windows in C++.

I livestream some of the coding of this project at:
twitch.tv/wraithedx

The goal for the project is unlimited. I want to keep adding onto it until I find it unmaintainable.

It currently has a rudimentary text-parser for user commands, and simple rooms that act
as game-states.

I am currently trying to figure out how to give all of the various types of Actors unique AI
within one simple base class: NPC. A factory loads all rooms and actors from text files, and
I would like to have a healer that you can pay to heal your wounds, an orc that attacks on site,
and a merchant that buys and sells wares (items not yet implemented). My current thought is to
make the NPC class a very large finite state machine, and have the actor text files contain
lots of tags, all of which can have different values and conditions to trigger.
