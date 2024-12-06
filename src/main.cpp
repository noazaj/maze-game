#include <iostream>

#include "game.h"
#include "maze.h"


int main()
{
    Game game(1700, 1000);
    Maze maze;

    char** new_maze = maze.create_maze(50, 50);
    maze.print_maze(new_maze);

    maze.increase_maze_size();

    char** larger_maze = maze.create_maze(50, 50);
    maze.print_maze(larger_maze);

    game.run();

    maze.delete_maze(new_maze);
    maze.delete_maze(larger_maze);

    return 0;
}