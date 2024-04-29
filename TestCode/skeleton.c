#include <stdio.h>
#include <stdlib.h>

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


int checkFile(const char *Filename){

    FILE *file = fopen (Filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file\n"); //Checking whether the file is available
    }
// Open the file and run the error checkers to see whether there is anything wrong with the file 
//  that is being tested

    char ch;
    int height = 0;
    int lineLength = 0;
    int width = 0;
    int startCount = 0;
    int endCount = 0;


    while((ch = fgetc(file)) != EOF) {
        if (ch != '\n') {
            lineLength++;
        }
        else {
            width = lineLength;
            //if (lineLength != width) {
                //fprintf(stderr, "Error: Inconsistent width of maze\n");

            //}
            height++;
            lineLength = 0;

        }


        if (ch != '#' && ch != 'S' && ch != 'E' && ch != ' ' && ch != '\n') {
            
            fprintf(stderr, "INVALID CHARACTERS IN MAZE\n");
            
            fclose(file);
            return 0;
        }   

        printf("%c", ch);
        if (ch == 'S') {
            startCount++;
          
        }


      

    }
    if (startCount != 1) {
        fprintf(stderr, "Error: Invalid amount of starts\n");
        printf("%d", startCount);
        return 0;
    }
    //fclose(file);

    if (height < MinDim || height > MaxDim || width < MinDim || width > MaxDim) {
        perror("Error: Dimensions are either too big or too small! \n");
        return 0;
    }

    return 1;

    
// This checks errors such as the maze is between 5 and 100 characters in each dimension
//Before that is checks that the file is valid and does exist 
}

int InitialiseMaze (Maze *maze, int height, int width, char *Filename) { //THIS ALLOCATES MEMORY FOR THE FILE

    FILE *file = fopen(Filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file\n");
        return 0;
    }

    maze->map = (char **)malloc(height * sizeof(char *));
    if (maze == NULL) {
        fprintf(stderr, "Allocation error\n");
        return 0;
    }

    for (int i = 0; i < height; i++) {
        map[i] = (char *)malloc(width * sizeof(char));
    
    }
    
    for (int i = 0; i< height; i++) {
        fgets(map[i], width + 1, file);
    }

    fclose(file);



    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (map[y][x] == 'S') {
                (*maze).start.y = y;
                (*maze).start.x = x;
            }
        } 
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (map[y][x] == 'E') {
                (*maze).end.y = y;
                (*maze).end.x = x;
            }
        }
    }
    



    fclose(file);
    return 1;


    
    //This will add the text file in which the maze is stored in, and add it to an array in the struct Maze.
    // this will ensure that the maze is loaded therefore meaning we can carry on with the rest of the functions such as CheckPosition

}

//int CheckPostion(int Starty; int Startx; int Endy; int Endx) {
//When the file is open the user should be starting at the S position.
//We are going to check that the co ordinates of the player position is correct as well as the user 
//starts in the correct position   
//This function will also check where the user is and checks whether the co ordinates of the player is the same as the end 
// Essentially chekcing whether the player has finished the maze after every move is inputted.
//    return 0;
//}
void GameControls() { //THIS TELLS THE USER WHAT THE GAME CONTROLS ARE
    //Defining the games the controls which can be easily called upon in the main function

    printf("W/w - Move up\n");
    printf("A/a - Move left\n");
    printf("S/s - Move down\n");
    printf("D/d - Move right\n");
    printf("Q/q - Quit\n");

}
int CheckMove(char move) { //THIS DEFINES EACH MOVE AND IF THE USER PUTS IN A WRONG MOVE 
    //This checks whether the user enters the correct letter to move such as

    if (move == 'w' || move == 'W' || move == 'A' || move == 'a' || move == 'S' || move == 's' || move == 'd' || move == 'D') {
        return 1;
    }
    else if (move == 'Q' || move == 'q') {
        return 2;
    }
    else {
        return 0;
    }
}

void ShowMaze(Maze *maze, Coordinates *player) {

    printf("\n");

    for (int y = 0; y < (*maze).height; y++) {

        for (int x = 0; x < (*maze).width; x++) {

            if (player->x == x && player->y == y) {

                printf("X");

            }
            else { 

                printf("%c", (*maze).map[y][x]);
        }   }
        printf("\n");
    }
}

int main(int argc, char *argv[]) { //MAIN FUNCTION

    char Filename[100];
    Coordinates *player;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_ARG_ERROR;
    }

    if(checkFile(argv[1]) == 0) {
        printf("Error: Bad filename\n");
        return EXIT_FILE_ERROR;
    }

    checkFile(Filename);

    int height;
    int width;
    Maze *maze = malloc(sizeof(maze));


    free((*maze).map);
    free(maze);

    GameControls();

    char move;
    printf("Enter your moves, (Press M for help): ");
    scanf("%c", &move);


    int x;
    int y;


    x = (*maze).start.x;
    y = (*maze).start.y;

    switch (move) {
        case 'W':
        case 'w':
            y += 1;
            break;
        case 'A':
        case 'a':
            x -= 1;
            break;
        case 'S':
        case 's':
            y -= 1;
            break;
        case 'D':
        case 'd':
            x += 1;
            break;
        case 'm':
        case 'M':
            ShowMaze(maze, player);
            break;
        case 'q':
        case 'Q':
        break;
        default:
            printf("Invlaid move! ");
            return 0;
            break;

        }




/* Checking the maze is correct aswell as the file being correct is going to be called in thr main fucntion. 
    - after initialising the maze, the game should load with the user in the correct position at the start line 

    */

    /*-Before the game starts all the error checkers will run through to ensure that the maze is valid 
      and that it is actually playable for the user and printing for each test whether its a Pass or a Fail
    
    
    Game Rules:
    - If the user inputs the wrong move, the game will carry on however the code should output that it is a wrong move
    - Therefore creating a while loop, detecting when the user will input anything other than WASD
    */

    /*-The user going into a wall also doesnt restart the maze, the user cannot go through the walls however.
    - Therefore to solve this we can make the spaces TRUE and the walls False, and ensure that
       the user can only go through something that is true.

    -When the user reaches the end the game terminates, therefore we can use another boolean.
    - Saying, when the user is anywhere else apart from the finish it holds a false value and when the user reaches
       the finish the code will return a vlaue TRUE. 
    - It will then congratulate the user and terminate the program

    - There also has to be part in the code in which the user can terminae the code by themself and restart the code 
    - this can be when the user enters a character such as R (restart) to ensure that the user can restart it.
 
    

    */
}