#pragma once

#include <iostream>
#include <cstdlib>

class Maze {
    private:
        int rows = 50;
        int columns = 50;

    public:
        char** create_maze(int rows, int columns);

        void increase_maze_size();

        void delete_maze(char** maze);

        void print_maze(char** maze);
};