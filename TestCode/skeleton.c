#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxDim 100
#define MinDim 5

#define EXIT_SUCCESS 0
#define EXIT_ARG_ERROR 1
#define EXIT_FILE_ERROR 2
#define EXIT_MAZE_ERROR 3

typedef struct {
    int x;
    int y;
    //Holds thse current y and x-axis of the player in the maze which will help us know whether the playter has
    // crossed the finish line or not 

} Coordinates;


typedef struct {
    char **map;
    int height; // height of the maze
    int width; // width of the maze
    Coordinates start;
    Coordinates end;
} Maze;


void checkFile(FILE *file, char *Filename, Maze *maze) {

    file = fopen(Filename, "r");

    int buffer_size = 101;
    char line_buffer[buffer_size];

    int height = 0;
    int width = 0;

    while (fgets(line_buffer, buffer_size, file) != NULL) {
        for (int i = 0; i < sizeof(line_buffer); i++) {
            if (line_buffer[i] == '\0' && width == 0) {
                width = i - 1;
            }
        }
        for (int i = 0; line_buffer[i] != '\0'; i++) {
            maze->map[height][i] = line_buffer[i];
        }
        height += 1;
    }

    fclose(file);

    maze->width = width;
    maze->height = height;

}


void InitialiseMaze (Maze *maze, Coordinates *player) { 

    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (maze->map[i][j] == 'S') {
                maze->start.x = i;
                maze->start.y = j;
                player->x = i;
                player->y = j; 
            }
            else if (maze->map[i][j] == 'E') {
                maze->end.x = i;
                maze->end.y = j;
            }
        }
    }

   

   
}

void allocateMemory (Maze *maze) {

    maze->map = (char **)malloc(MaxDim * sizeof(char *));  // Allocate memory for rows
if (maze->map == NULL) {
    fprintf(stderr, "Memory allocation failed for maze->map\n");
    exit(EXIT_FAILURE);  // Or handle the error as appropriate
}

for (int i = 0; i < MaxDim; i++) {
    maze->map[i] = (char *)malloc(MaxDim * sizeof(char));  // Allocate memory for columns of each row
    if (maze->map[i] == NULL) {
        fprintf(stderr, "Memory allocation failed for maze->map[%d]\n", i);
        // Free previously allocated memory before exiting
        for (int j = 0; j < i; j++) {
            free(maze->map[j]);
        }
        free(maze->map);
        exit(EXIT_FAILURE);  // Or handle the error as appropriate
    }
}
    
    
}


void GameControls() { //THIS TELLS THE USER WHAT THE GAME CONTROLS ARE
    //Defining the games the controls which can be easily called upon in the main function

    printf("W/w - Move up\n");
    printf("A/a - Move left\n");
    printf("S/s - Move down\n");
    printf("D/d - Move right\n");
    printf("Q/q - Quit\n");

}
void CheckMove(char move, Coordinates *player) { //THIS DEFINES EACH MOVE AND IF THE USER PUTS IN A WRONG MOVE 
    //This checks whether the user enters the correct letter to move such as
    switch (move) {
        case 'a':
        case 'A':
            player->y -= 1;
            break;
        case 'w':
        case 'W':
            player->x -= 1;
            break;
        case 's':
        case 'S':
            player->x += 1;
            break;
        case 'd':
        case 'D':
            player->y += 1;
            break;
        default:
            break;

    }
   
}

void ShowMaze(Maze *maze, Coordinates *player) {

    printf("\n");

        for (int i = 0; i < maze->height; i++) {

            for (int j = 0; j < maze->width; j++) {

                if (player->x == i && player->y == j) {

                    printf("X");

                }
                else { 

                    printf("%c", maze->map[i][j]);
                }   
            }
        printf("\n");  
        }  
   

    //DONT CHANGE   

}

void hasWon (Maze *maze, Coordinates *player) {
    if (player->x == maze->end.x || player->y == maze->end.y) {
        printf("Congratulations, you have won! \n");
    }
    
} 


int main(int argc, char *argv[]) { //MAIN FUNCTION

    char Filename[100];
    FILE file;

    if (argc != 2) {
        printf("Usage: maze <filename>");
        return EXIT_ARG_ERROR;
    }
    Maze maze;
    Coordinates player;

    allocateMemory(&maze);

    strcpy(Filename, argv[1]);

    checkFile(&file, Filename, &maze);
    InitialiseMaze(&maze, &player);
    char move;
    while (1) {
        printf("Enter moves: W,A,S,D... Q to quit and M to show map...\n");
        ShowMaze(&maze, &player);

        printf("Enter move: ");
        scanf(" %c", &move);

        CheckMove(move, &player);
    }




}