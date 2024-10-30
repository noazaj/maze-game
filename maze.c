#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int get_rows() {
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

int get_columns() {
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

int main(void) {
    printf("Welcome to the Maze Game!\n");
    printf("Please enter the amount of rows and columns you would like for the maze size below.\n\n");

    int rows = get_rows();
    int columns = get_columns();

    printf("The maze will be created with values %d and %d.", rows, columns);

    return 0;
}

