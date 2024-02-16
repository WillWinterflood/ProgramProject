#!/bin/bash

FileName = "Maze1"
#This first if statement checks whether the FileName exists 
if [-f "$FileName"]; then 
    echo "The file '$FileName' exists" 
    exit 0 
else 
    #printing out an error message if the file does not exist 
    echo "Error: The file '$FileName' does not exist"
    exit 1
fi

#These error messages are checking whether the length of the maze is between 5 and 100 characters

CharCount = $((wc -c < "$FileName"))

if (CharCount < 5); then 
    echo "Error: The maze is shorter than 5 characters."
    exit 1
fi

if (CharCount > 100); then
    echo "Error: The maze is above 100 characters."
    exit 1
fi

LineCount = $(wc -1 < "$FileName")

if (LineCount)





