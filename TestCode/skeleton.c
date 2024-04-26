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


int CheckFile(char Filename){
// Open the file and run the error checkers to see whether there is anything wrong with the file 
//  that is being tested
    FILE *file = fopen(Filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
    }
    for (int i = 0; i < (*maze).width; i++) {
        char ch;
        fscanf(file, " %c", &ch);
        if (ch != ' ' && ch != '#' && ch != 'S' && ch != 'E') {
            perror("Wrong characters in file, unacceptable file");
        }
    }
// This checks errors such as the maze is between 5 and 100 characters in each dimension
//Before that is checks that the file is valid and does exist 
}

int IntialiseMaze (Maze *maze, int height, int width) {

    FILE *file = fopen(Filename, "r");
    if (file = NULL) {
        perror("Unable to open file");
    }

    fscanf(file, "%d %d", &(* maze).width, &(* maze).height);

    (*maze).map = (char **)malloc(height * sizeof(char *)); // Allocating memory the size of the height of the map

    int i;
    for (i = 0; i < height; i++) {
        (*maze).map[i] = (char *)malloc(width * sizeof(char)); // When there is a row, there is also a column. Therefore, by using a FOR loop we can allocate memory easily
    }

    for (i = 0; i < height; i++) {
        int n;
        for (n = 0; n < width; n++) {
            if ((*maze).map[i][n] = '#') {
                return 0;
            }
        }
    }
    
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
void GameControls() {
    //Defining the games the controls which can be easily called upon in the main function

    printf("W/w - Move up\n");
    printf("A/a - Move left\n");
    printf("S/s - Move down\n");
    printf("D/d - Move right\n");
    printf("Q/q - Quit\n");

}
int CheckMove(char move) {
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

int main(int argc, char *argv[]) {

    char Filename[101];
    Maze maze;
    Coordinates User;

    if (!checkFile(Filename)) {
        return 1;
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
    char input;

    GameControls();

    printf("Please start: ");
    //while the use hasnt finished the maze...
    scanf("%c", &input);
    int result = CheckMove(input);

    if (result == 0) {
        printf("Wrong input, Try again\n");
    }
    //end while loop
    return 0;
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