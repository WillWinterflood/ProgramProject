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

    file = fopen(Filename, "r"); // reads the open file

    int buffer_size = 101;
    char line_buffer[buffer_size];
    int height = 0;
    int width = 0;

    while (fgets(line_buffer, buffer_size, file) != NULL) { 
       
       if (strlen(line_buffer) >= buffer_size - 1) {  //compares the bufferSize and the length of the line to ensure there is no segmentation fault. 
            printf("Length of line bigger than buffer\n");
            exit(EXIT_MAZE_ERROR);
       }
       int lineLength = strlen(line_buffer);
       width = lineLength;

       for (int i = 0; i < lineLength; i++) {
            char ch = line_buffer[i];
            if (ch != 'S' && ch != 'E' && ch != ' ' && ch != '#' && ch != '\n') { //Checks the valid characters in the file.
                printf("Incorrect chars in this file");
                exit(EXIT_MAZE_ERROR);
            }
       }

       strncpy(maze->map[height], line_buffer, buffer_size - 1);
      
       height++;
       
       

    }
   

    fclose(file);

    maze->width = width;
    maze->height = height;

}


void InitialiseMaze (Maze *maze, Coordinates *player) { 

    int start = 0;


    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (maze->map[i][j] == 'S') {
                maze->start.x = i;
                maze->start.y = j;
                player->x = i;
                player->y = j; 
                start++;
            }
            else if (maze->map[i][j] == 'E') {
                maze->end.x = i;
                maze->end.y = j;
            }
        }
    }

    if(start >= 2) {
        printf("Too many starts\n");
        exit(EXIT_MAZE_ERROR);
    }
    else if (start == 0) {
        printf("No starts found\n");
        exit(EXIT_MAZE_ERROR);
    } 

   

   
}

void allocateMemory (Maze *maze) {

    //These lines were inspiration of https://chat.openai.com/share/cadbd38c-2d4a-49a0-9dc9-c46898a56129

    maze->map = (char **)malloc(MaxDim * sizeof(char *)); 

    for (int i = 0; i < MaxDim; i++) {
        maze->map[i] = (char *)malloc(MaxDim * sizeof(char));  

        if (maze->map[i] == NULL) {
           
            for (int j = 0; j < i; j++) {
                free(maze->map[j]);
            }
            free(maze->map);
            exit(EXIT_FAILURE);  
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
void CheckMove(char move, Coordinates *player, Maze *maze) { //THIS DEFINES EACH MOVE AND IF THE USER PUTS IN A WRONG MOVE 
    //This checks whether the user enters the correct letter to move such as
    
    switch (move) {
        case 'a':
        case 'A':
            if ((maze->map[player->x][player->y - 1]) == '#' ) {

                printf("Cant go into a wall, try another move!\n");
                player->y == 0;

            }
            else {
                
                player->y -= 1;
            
            } 
            break;
        case 'w':
        case 'W':
        if ((maze->map[player->x - 1][player->y]) == '#' ) {

            printf("Cant go into a wall, try another move!\n");
            player->x == 0;

        }
        else {
                
            player->x -= 1;
            
        } 
            break;
        
        
        case 's':
        case 'S':
            if ((maze->map[player->x + 1][player->y]) == '#' ) {

                printf("Cant go into a wall, try another move!\n");
                player->x == 0;

            }
            else {
                
                player->x += 1;
            
            } break;
        case 'd':
        case 'D':
            if ((maze->map[player->x][player->y + 1]) == '#' ) {

                printf("Cant go into a wall, try another move!\n");
                player->y == 0;

            }
            else {
                
                player->y += 1;
            
            } 
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
   
 

}

void hasWon (Maze *maze, Coordinates *player) {

  
    if (player->x == maze->end.x && player->y == maze->end.y) {
        printf("Congrats, you have won!\n");
        exit(EXIT_SUCCESS);
    }
    
} 


int main(int argc, char *argv[]) { //MAIN FUNCTION

    char Filename[100];
    FILE *file;

    if (argc != 2) {
        printf("Usage: maze <filename>");
        return EXIT_ARG_ERROR;
    }
    Maze maze;
    Coordinates player;

    allocateMemory(&maze);

    strcpy(Filename, argv[1]);

    checkFile(file, Filename, &maze);
    InitialiseMaze(&maze, &player);

    GameControls();
    char move;
    while (1) {

        printf("Enter moves: W,A,S,D... Q to quit and M to show map...\n");
        ShowMaze(&maze, &player);

        printf("Enter move: ");
        scanf(" %c", &move);

  
        CheckMove(move, &player, &maze);
        if (move =='Q' || move == 'q') {
            printf("Quitting...\n");
            return EXIT_SUCCESS;
        }
        
        hasWon(&maze, &player);

    }




}