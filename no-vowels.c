/*
Write a function to replace vowels with numbers
Get practice with strings
Get practice with command line
Get practice with switch

Pseudocode:
If only one command-line argument, call function 'replace'
In the function 'replace', iterate through every character in input
If a character falls into A/E/I/O/a/e/i/o, change that character into the numerical version
Print the converted string

Ryan Ho
27/10/22
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string argv);

int main(int argc, string argv[]) // argc is variable that includes how many arguments user inputs, and argv is where user input is stored
{
    if (argc == 2) // Only run if one argument only after input
    {
        replace(argv[1]); // Run function "replace" with the word after user input
    }
    else
    {
        printf("Please try again. Make sure to enter the word you want converted right after the run line.\n"); // Error message if more/less than one argument
        return 1; // Error return 1
    }
}

string replace(string text)
{
    for(int i = 0; i < strlen(text); i++) // Loop to go through every character in input
    {
        if (text[i] == 'a' || text[i] == 'A') // If character is A/a
        {
            text[i] = '6'; // Replace the character with 6
        }
        else if (text[i] == 'e' || text[i] == 'E') // If character is E/e
        {
            text[i] = '3'; // Replace the character with 3
        }
        else if (text[i] == 'i' || text[i] == 'I') // If character is I/i
        {
            text[i] = '1'; // Replace the character with 1
        }
        else if (text[i] == 'o' || text[i] == 'O') // If character is O/o
        {
            text[i] = '0'; // Replace the character with 0
        }
    }
    printf("%s\n", text); // Print the converted text
    return 0;
}
