#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

int get_rows()
{
    long int rows;
    char *endptr;
    int flag = 0;
    do
    {
        char s[MAX];
        printf("Rows: ");
        if (fgets(s, MAX, stdin) == NULL) {
            printf("\nPlease enter a valid input stream\n");
        } else {
            rows = strtol(s, &endptr, 10);
            if (endptr == s) {
                printf("Please enter a valid input stream\n");
            } else if (*endptr != '\n') {
                printf("Invalid character: %c\n", *endptr);
            } else {
                flag = 1;
            }
        }
    } while (!flag);
    return rows;
}

int get_columns()
{
    long int columns;
    char *endptr;
    int flag = 0;
    do
    {
        char s[MAX];
        printf("Columns: ");
        if (fgets(s, MAX, stdin) == NULL) {
            printf("\nPlease enter a valid input stream\n");
        } else {
            columns = strtol(s, &endptr, 10);
            if (endptr == s) {
                printf("No digits were found\n");
            } else if (*endptr != '\n' && *endptr != '\0') {
                printf("Invalid character: %c\n", *endptr);
            } else {
                flag = 1;
            }
        }
    } while (!flag);
    return columns;
}

char** create_maze(int rows, int columns)
{
    char** maze = (char**)(malloc(rows * sizeof(char*)));

    for (int i = 0; i < rows; i++) {
        maze[i] = (char*)(malloc(columns * sizeof(char)));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            maze[i][j] = WALL;
        }
    }

    return maze;
}

int main(void)
{
    char** maze;

    printf("Welcome to the Maze Game!\n");
    printf("Please enter the amount of rows and columns you would like for the maze size below.\n\n");

    int rows = get_rows();
    int columns = get_columns();

    printf("The maze will be created with values %d and %d.\n", rows, columns);

    maze = create_maze(rows, columns);
    
    for (int i = 0; i < rows; i++) {
        printf("\n");
        for (int j = 0; j < columns; j++) {
            printf("%c", maze[i][j]);
        }
    }

    printf("\n");
    return 0;
}

