% ####################################################################
% Logic puzzle solver.
%
% Read definition to prolog:
%   ['puzzle.pl'].
%
% 2) Ask for solutions:
%   solve(Batman,Dibii,Jake).
%
% Aiden Tallet
% 19/2023
% ####################################################################
 
all_members([H],L2) :- member(H,L2).
all_members([H|T],L2) :- member(H,L2), all_members(T, L2).
 
solve(Batman,Dibii,Jake) :-
% all Cats
Batman = [Batman_Activity, Batman_Kitten,Batman_Female],
Dibii = [Dibii_Activity, Dibii_Kitten, Dibii_Female],
Jake = [Jake_Activity, Jake_Kitten, Jake_Female],
% grouping
All = [Batman,Dibii,Jake],
% ensure all values exist once
all_members([lazer,sleep,ball], [Batman_Activity, Dibii_Activity, Jake_Activity]),
all_members([1, 2, 3], [Batman_Kitten, Dibii_Kitten, Jake_Kitten]),
all_members([ruby,spot,starbuck], [Batman_Female, Dibii_Female, Jake_Female]),
% clue 1
member([ball, 1, Batman_Female], All),
dif(Batman_Female,starbuck),
%clue 2
member([lazer, Dibii_Kitten, Dibii_Female], All),
%clue 3
member([sleep, _, ruby], All),
%clude 4 -- note that the math for the direct interpretation of the clue would not work, so it is hard coded as 3 and 1 respectively
member([lazer, 3, starbuck], All).