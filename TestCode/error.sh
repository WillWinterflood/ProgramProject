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

echo -n "Testing if too many arguments have been entered - "
if grep -q "Error: Too many arguments entered" tmp; then
    echo "PASS"
else 
    echo "FAIL"
    cat tmp
fi

echo -e "~~Testing for File errors: ~~"

echo -n "Testing for invalid filename: - "
echo "noF" | ./errorchecker > tmp 
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


echo -e "~~Testing for Maze errors:~~"

echo -n "Checking for mazes with no start: - "
echo "NoS" | ./errorchecker > tmp

if grep -q "Error: This maze does not have a start" tmp; then
    echo "FAIL"
else
    echo "PASS"
    cat tmp
fi
#Note: The maze can be impossible and this is why there is no error code to check for 
  # there being an end. However, there always to be a start
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
    echo "FAIL"
else
    echo "PASS"
    cat tmp
fi 

echo -n "Checking if the maze contains the right characters: - "
echo "char" | ./errorchecker > tmp 

if grep -q "Error: There are some wrong characters in the maze" tmp; then
    echo "FAIL"
else
    echo "PASS"
    cat tmp 
fi 

echo -n "Checking for multiple starting points: - "
echo ">start" | ./errorchecker > tmp

if grep -q "Error: There are too many starting points" tmp; then
    echo "FAIL"
else
    echo "PASS"
fi

echo -n "Checking for multiple end points: - "
echo ">end" | ./errorchecker > tmp

if grep -q "Error: There are too many end points" tmp; then
    echo "FAIL"
else
    echo "PASS"
fi

echo -e "~~Testing for incorrect inputs~~"

echo -n "Test 'a' user input: - "
echo "a"| ./errorchecker > tmp

if grep -q "Error: Invalid input" tmp; then
    echo "FAIL"
else
    echo "PASS"
fi

echo -n "Test 'A' user input: - "
echo "A"| ./errorchecker > tmp

if grep -q "Error: Invalid input" tmp; then
    echo "FAIL"
else
    echo "PASS"
fi

echo -n "Test 'w' user input: - "
echo "w"| ./errorchecker > tmp

if grep -q "Error: Invalid input" tmp; then
    echo "FAIL"
else
    echo "PASS"
fi

echo -n "Test 'W' user input: - "
echo "W"| ./errorchecker > tmp

if grep -q "Error: Invalid input" tmp; then
    echo "FAIL"
else
    echo "PASS"
fi

echo -n "Test 's' user input: - "
echo "s"| ./errorchecker > tmp

if grep -q "Error: Invalid input" tmp; then
    echo "FAIL"
else
    echo "PASS"
fi

echo -n "Test 'S' user input: - "
echo "S"| ./errorchecker > tmp

if grep -q "Error: Invalid input" tmp; then
    echo "FAIL"
else
    echo "PASS"
fi

echo -n "Test 'd' user input: - "
echo "d"| ./errorchecker > tmp

if grep -q "Error: Invalid input" tmp; then
    echo "FAIL"
else
    echo "PASS"
fi

echo -n "Test 'D' user input: - "
echo "D"| ./errorchecker > tmp

if grep -q "Error: Invalid input" tmp; then
    echo "FAIL"
else
    echo "PASS"
fi

rm -f tmp



