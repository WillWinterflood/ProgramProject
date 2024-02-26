#!/bin/bash

FileName = "ErrorTooShort"
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

CharCount = $(wc -c < "$FileName")

if (CharCount < 5); then 
    echo "Error: The maze is shorter than 5 characters."
    exit 1
fi

if (CharCount > 100); then
    echo "Error: The maze is above 100 characters."
    exit 1
fi

#These error codes check the height of the maze is between 5 and 100 characters
LineCount = $(wc -1 < "$FileName")

if (LineCount < 5); then
    echo "Error: The maze is less than 5 characters in height."
    exit 1
fi

if (LineCount > 100); then
    echo "Error: The maze is greater than 100 characters in height."
    exit 1
fi

#This error checker is cheking if the file has only hashtags,S,E and spaces 

if grep -qE -v '^[# SE]*$' "$FileName"; then
    echo "Error: The file doesnt contain the right characters"
    exit 1
else
    echo "File has valid characters"
    exit 0
fi

#Checking whether they input the correct move
read -p "AWSD" move 

if grep -q "^$move$" "FileName"; then
    echo "Valid Move"
else
    echo "Invalid Move"












