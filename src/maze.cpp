#include "maze.h"

char** Maze::create_maze(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;

    char** maze = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        maze[i] = new char[columns];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1) {
                maze[i][j] = '#';
            } else {
                maze[i][j] = (rand() % 4 == 0) ? '#' : ' ';
            }
        }
    }

    return maze;
}

void Maze::increase_maze_size()
{
    rows += 50;
    columns += 50;
}

void Maze::delete_maze(char** maze)
{
    for (int i = 0; i < rows; ++i) {
        delete[] maze[i];
    }
    delete[] maze;
}

void Maze::print_maze(char** maze)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << maze[i][j];
        }
        std::cout << '\n';
    }
}