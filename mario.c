/*
Mario
Pseudocode:
Get integer to collect height from user
    Reject input if n<=0 or n>8
Print spaces and call hashtag function
Print gap
Call hashtag function for right pyramid
Print line to move onto next line
Ryan Ho
6/10/2022
*/

#include <cs50.h>
#include <stdio.h>

void hash(int line);
int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    for (int line = 1; line <= height; line++) // Changing line value after completion of each line, stopping until line reaches height input
    {
        for (int space = 1; space <= height - line; space++) // For loop to determine number of spaces (height - line number = number of spaces needed)
        {
            printf(" ");
        }
        hash(line);
        printf("  "); // Print two spaces after right align hashtags
        hash(line);
        printf("\n");
    }

}

// Function
void hash(int line) // Void because nothing to return
{
    for (int digit = 1; digit <= line; digit++) // For loop to print hashtags needed for each step / columns with left alignment
    {
        printf("#");
    }
}
