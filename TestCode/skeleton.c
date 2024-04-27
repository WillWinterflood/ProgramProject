#include <stdio.h>
#include <stdlib.h>

#define MaxDim 100
#define MinDim 5


//Defining all the user movements 

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
        fprintf(stderr, "Unable to open file"); //Checking whether the file is available
    }
// Open the file and run the error checkers to see whether there is anything wrong with the file 
//  that is being tested

    char ch;
    int width = 0;
    int height = 0;
    int lineLength = 0;

    int startCount = 0;
    int endCount = 0;


    while((ch = fgetc(file)) != EOF) {
        if (ch != '\n') {
            lineLength++;
        }
        else {
            if (lineLength != width) {
                fprintf(stderr, "Error: Inconsistent width of maze");
                return 0;

            }
            height++;
            lineLength = 0;

        }


        if (ch != '#' && ch != 'S' && ch != 'E' && ch != ' ') {
            
            fprintf(stderr, "INVALID CHARACTERS IN MAZE");
            
            fclose(file);
            return 0;
        }   

        if ( ch == 'S') {
            startCount++;
        }
        if (startCount != 1) {
            fprintf(stderr, "Error: Invalid amount of starts");
            return 0;
        }

    }
    fclose(file);

    if (height < MinDim || height > MaxDim || width < MinDim || width > MaxDim) {
        perror("Error: Dimensions dont meet criteria");
        return 0;
    }

    return 1;

    
// This checks errors such as the maze is between 5 and 100 characters in each dimension
//Before that is checks that the file is valid and does exist 
}

int IntialiseMaze (Maze *maze, int height, int width, char *Filename) { //THIS ALLOCATES MEMORY FOR THE FILE

    FILE *file = fopen(Filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file");
        return 0;
    }

    char **map = (char **)malloc(height * sizeof(char *));
    if (map == NULL) {
        fprintf(stderr, "Allocation error");
        return 0;
    }

    for (int i = 0; i < height; i++) {
        map[i] = (char *)malloc(width * sizeof(char));
        
        for (int x = 0; x < i; x++) {
            
        }
        fclose(file);
    }

    Coordinates start, end;

    for (int n = 0; n < (*maze).height; n++) {

    }

    (*maze).map = map;
    (*maze).height = height;
    (*maze).width = width;
    (*maze).start = start;
    (*maze).end = end;

    return maze;


    
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

int main(int argc, char *argv[]) { //MAIN FUNCTION

    char Filename[100];
    printf(" ");
    scanf("%s", Filename);

    checkFile(Filename);

    Maze *maze = IntialiseMaze(Filename);

    for (int i = 0; i < (*maze).height; i++) {
        free((*maze).height[i]);
    }

    free((*maze).map);
    free(maze);

    printf(GameControls());

    if (CheckMove() == 0) {
        ("Wrong move please enter a valid control");
    }
    else if (CheckMove() == 2) {
        printf("Quitting...\n");
        exit(0);
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