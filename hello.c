// CS50 Practice 1 Hello

// Include libraries for get_string/printf
#include <stdio.h>
#include <cs50.h>

// Function
int main(void)
{
// Assign variable to the user's response to get_string
    string name = get_string("What is your name?\n");

// Output hello, name variable
    printf("hello, %s\n", name);
}
