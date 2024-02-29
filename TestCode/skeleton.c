#include <stdio.h>

typedef struct {
    int x;
    int y;
} Coordinates;


typedef struct {
    Coordinates Start;
    Coordinates End; // In order to know when the user has crossed the finish line
    int Lines; // height of the maze
    int Chars; // width of the maze
} Maze;

typedef struct {
    char Up;
    char Down;
    char Left;
    char Right;
} Controls; // all the controls for AWSD

struct StartingPosition {

}

int main(){
// open the file and run the error checkers to see whether there is anything wrong with the file that is being tested

}