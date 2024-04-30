/**
 * @file maze.c
 * @author William Winterflood
 * @brief Code for the maze game for COMP1921 Assignment 2
 * NOTE - You can remove or edit this file however you like - this is just a provided skeleton code
 * which may be useful to anyone who did not complete assignment 1.
 */

#include <stdio.h>
#include <stdlib.h>

// defines for max and min permitted dimensions
#define MAX_DIM 100
#define MIN_DIM 5

// defines for the required autograder exit codes
#define EXIT_SUCCESS 0
#define EXIT_ARG_ERROR 1
#define EXIT_FILE_ERROR 2
#define EXIT_MAZE_ERROR 3

typedef struct __Coord
{
    int x;
    int y;
} coordinates;

typedef struct __Maze
{
    char **map;
    int height;
    int width;
    coordinates start;
    coordinates end;
} Maze;

/**
 * @brief Initialise a maze object - allocate memory and set attributes
 *
 * @param this pointer to the maze to be initialised
 * @param height height to allocate
 * @param width width to allocate
 * @return int 0 on success, 1 on fail
 */
int create_maze(Maze *maze, int height, int width) {

    if (height < MIN_DIM || width < MIN_DIM || height > MAX_DIM || width > MAX_DIM) {
        return EXIT_MAZE_ERROR;
    }

    (char **)malloc(height * sizeof(char *));

    for (int i = 0; i < height; i++) {
        (*maze).map[i] = (char *)malloc(width * sizeof(char));
        if(maze->map == NULL) {
            for (int x = 0; x < height; x++) {
                free(maze->map[i]);
            }
            free(map);
        }

    }

}

/**
 * @brief Free the memory allocated to the maze struct
 *
 * @param this the pointer to the struct to free
 */
void free_maze(Maze *maze)
{
}

/**
 * @brief Validate and return the width of the mazefile
 *
 * @param file the file pointer to check
 * @return int 0 for error, or a valid width (5-100)
 */
int get_width(FILE *file)
{
}

/**
 * @brief Validate and return the height of the mazefile
 *
 * @param file the file pointer to check
 * @return int 0 for error, or a valid height (5-100)
 */
int get_height(FILE *file)
{
}

/**
 * @brief read in a maze file into a struct
 *
 * @param this Maze struct to be used
 * @param file Maze file pointer
 * @return int 0 on success, 1 on fail
 */
int read_maze(Maze *maze, FILE *file) {
    char ch;
    int width = 0;
    int height = 0;

    while (ch = fgetc(file) != EOF) {
        if (ch != '\n') {
            if (ch == 'S' || ch == 'E' || ch == ' ' || ch == '#') {
                width++;

            }
            else {
                printf("Invalid characters in file\n");
                return EXIT_FILE_ERROR;

            }
        }
        else {
            height++;
        }
    }
    printf("%d %d", height, width);
}

/**
 * @brief Prints the maze out - code provided to ensure correct formatting
 *
 * @param this pointer to maze to print
 * @param player the current player location
 */
void print_maze(Maze *maze, coordinates *player)
{
    // make sure we have a leading newline..
    printf("\n");
    for (int i = 0; i < maze->height; i++)
    {
        for (int j = 0; j < maze->width; j++)
        {
            // decide whether player is on this spot or not
            if (player->x == j && player->y == i)
            {
                printf("X");
            }
            else
            {
                printf("%c", maze->map[i][j]);
            }
        }
        // end each row with a newline.
        printf("\n");
    }
}

/**
 * @brief Validates and performs a movement in a given direction
 *
 * @param this Maze struct
 * @param player The player's current position
 * @param direction The desired direction to move in
 */
void move(Maze *maze, coordinates *player, char direction)    {

}

/**
 * @brief Check whether the player has won and return a pseudo-boolean
 *
 * @param this current maze
 * @param player player position
 * @return int 0 for false, 1 for true
 */
int has_won(Maze *maze, coordinates *player)
{
}

int main(int argc[], char *argv[])  {
    // check args

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_ARG_ERROR;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "File Invalid\n");
        return EXIT_ARG_ERROR;
    }

    // set up some useful variables (you can rename or remove these if you want)
    coordinates *player;
    Maze *maze_Maze = malloc(sizeof(Maze));
    FILE *file;

    // open and validate mazefile

    // read in mazefile to struct

    // maze game loop

    // win

    // return, free, exit
}