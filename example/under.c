#include <stdio.h>
#include <string.h>

// Structs and Memory 
struct person
{
 char name[5];  
 double age;            
 char gender;
    
};
int main()
{
    struct person Person1;
    printf("%lu\n ",sizeof(Person1));
    
}