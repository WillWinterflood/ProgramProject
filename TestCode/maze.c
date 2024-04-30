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

coordinates player = {0,0};
void create_maze(Maze *maze, int height, int width) {


   

    maze->map = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        maze->map[i] = malloc((width + 1) * sizeof(char));
    }

}

void free_maze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->map[i]);
    }
    free(maze->map);
}


int get_width(FILE *file) {
    rewind(file);
    int width = 0;
    int maxWidth = 0;
    int currentWidth = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {

            if (currentWidth > maxWidth) {
                maxWidth = currentWidth;
            }
            currentWidth = 0;
        }
        else {
            if (ch == 'S' || ch == 'E' || ch == ' ' || ch == '#') {
                currentWidth++;
            }
            else {
                fprintf(stderr, "Not correct characters in file\n");
                return EXIT_FILE_ERROR;
            }
            
        }
    }

    
    if (maxWidth < 5 || maxWidth > 100) {
        fprintf(stderr, "Dimensions not right %d", width);
        return EXIT_FILE_ERROR;
    }
    maxWidth = width;

    if ( width < MIN_DIM || width > MAX_DIM) {
        return EXIT_MAZE_ERROR;
    }
    return width;
    
}



int get_height(FILE *file)  {

    rewind(file);
    char ch;
    int height = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            height++;
        }
    }
    if (height < 5 || height > 100) {
        fprintf(stderr, "Dimensions too big ");
        return EXIT_FILE_ERROR;
    }
     if (height < MIN_DIM || height > MAX_DIM ) {
        return EXIT_MAZE_ERROR;
    }
    return height;
    
}

void read_maze(Maze *maze, FILE *file, coordinates *player) {
    rewind(file);
    int width = get_width(file);
    int height = get_height(file);

    // Allocate memory for the maze map
    maze->map = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        maze->map[i] = malloc((width + 1) * sizeof(char));
    }

    // Read the maze from file
    for (int i = 0; i < height; i++) {
        fgets(maze->map[i], width + 1, file);
    }

    // Find and set the player's starting position
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze->map[i][j] == 'S') {
                maze->start.x = j;
                maze->start.y = i;
                player->x = j;
                player->y = i;
                return; // Exit loop after finding the starting position
            }
        }
    }
}


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


void movement(Maze *maze, coordinates *player, char move)    {

    int new_x = player->x;
    int new_y = player->y;

    // Update coordinates based on the move
    switch (move) {
        case 'w': // Up
            new_y--;
            break;
        case 'a': // Left
            new_x--;
            break;
        case 's': // Down
            new_y++;
            break;
        case 'd': // Right
            new_x++;
            break;
        case 'q':
        case 'Q':
            exit(1);
        default:
            // Invalid move
            return;
    }

    // Check if the new position is valid
    if (new_x >= 0 && new_x < maze->width && new_y >= 0 && new_y < maze->height &&
        maze->map[new_y][new_x] != '#') {
        // Update player position
        player->x = new_x;
        player->y = new_y;
    }
    
}


int has_won(Maze *maze, coordinates *player)  {

}

int main(int argc, char *argv[])  {

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_ARG_ERROR;
    }
 
    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "File Invalid\n");
       
        return EXIT_ARG_ERROR;
    }




    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    int height = get_height(file);
    int width = get_width(file);
    
    
    coordinates *player = malloc(sizeof(coordinates));
    Maze *maze = malloc(sizeof(Maze));


    player->x = maze->start.x;
    player->y = maze->start.y;

    create_maze(maze, height, width);
    read_maze(maze, file, player);
    
    char move = '\0';
    while (move != 'q' || move != 'Q') {
      


        print_maze(maze, player);

        printf("Enter moves W/A/S/D: ");
        scanf(" %c", &move);

    }



    fclose(file);
    free_maze(maze);
    free(maze);
    free(player);


    return EXIT_SUCCESS;

   

    
}