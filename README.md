# Lem_in

The goal of this project is to find a way to get n ants accross the anthill.

At the beginning of the game, all the ants are in the room ##start. The goal is
to bring them to the room ##end with as few turns as possible.

usage ./lem_in [-debug] [-count] [-path] [-print] < anthill.txt

The options are as follows:

     -debug    Check the validity of anthill.txt.
     
     -count    Display the number of laps necessary to solve the problem.
     
     -path     Display (one of) the smallest path from start_room to end_room.
     
     -print    Display the structure of the anthill.
