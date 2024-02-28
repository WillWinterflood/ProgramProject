#!/bin/bash

gcc skeleton.c -o errorchecker

echo -e "~~ Testing for Errors: ~~"

ehco -e "~~Argument Error testing: ~~"

echo -n "Testing for any argument entered - "
echo "NoArg" | ./errorchecker 1 < Maze.txt > tmp 

if grep -q "Error: No Argument entered" tmp; then
    echo "FAIL"
else
    echo "PASS"
    cat tmp
fi

#echo "NoArg" | ./errorchecker 1 < Maze.txt > tmp

echo -n "Testing if too many arguments have been entered - "
echo "Arg>" | ./errorchecker 1 < Maze.txt > tmp 

if grep -q "Error: Too many arguments entered" tmp; then
    echo "PASS"
else 
    echo "FAIL"
    cat tmp
fi

echo -e "~~Testing for File errors: ~~"

echo -n "Testing for invalid filename: - "
echo "no" | ./errorchecker > tmp 

if grep -q "Error: Invalid filename" tmp; then
    echo "FAIL"
else
    echo "PASS"
    cat tmp
fi 

echo -n "Checking file existence: - "
echo "ex" | ./errorchecker > tmp

if grep -q "Error: File not found/ does not exist" tmp; then
    echo "FAIL"
else
    echo "PASS"
    cat tmp
fi

echo -n "Checking for too many filenames: - " #Isnt this just argument checking?
echo ">name" | ./errorchecker > tmp
#
echo -n "Checking for mazes with no start: - "
echo "NoS" | ./errorchecker > tmp

if grep -q "Error: This maze does not have a start" tmp; then
    echo "FAIL"
else
    echo "PASS"
    cat tmp
fi

echo -n "Checking for mazes with no end: - "
echo "NoE" | ./errorchecker > tmp

if grep -q "Error: This maze does not have an end point" tmp; then
    echo "FAIL"
else
    echo "PASS"
    cat tmp
fi 

echo -n "Checking that the maze is a rectangle/square: - " 
echo "srec" | ./errorchecker > tmp

if grep -q "Error: This maze is not a rectangle/square" tmp; then
    echo "FAIL"
else
    echo "PASS"
    cat tmp
fi

echo -n "Checking if maze is too big: - "
echo "big" | ./errorchecker > tmp 

if grep -q "Error: This maze is too big" tmp; then
    echo "FAIL"
else
    echo "PASS"
    cat tmp
fi

echo -n "Checking if the maze is too small: - "
echo "smal" | ./errorchecker > tmp 

if grep -q "Error: This maze is too small" tmp; then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi 

echo -n "Checking if the maze contains the right characters: - "
echo "char" | ./errorchecker > tmp 

if grep -q "Error: There are some wrong characters in the maze" tmp; then
    echo "PASS"
else
    echo "FAIL"
    cat tmp 
fi 








