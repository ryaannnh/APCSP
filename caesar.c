/*
Objective: To implement a program that encrypts messages using Caesar’s cipher.

Pseudocode:
Cmd-line input for word
	Check argc to see if 0, return 1 and error message
Func to check if only_digits (call in main for argv[1])
User input for how many to shift
With how many to shift, use ASCII to shift.
For loop to repeat +1 until how many to shift reached
Isalpha to only shift alphabet
If/else to control not going over (restarting from a/A at specific ASCII for each case)
	Reset to 65 when reached 90 ifupper
	Reset to 97 when reached 122 iflower
Print final

03/11/2022
Ryan Ho
*/

#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string argument); // Boolean to check if it's digit with input of argument to check if it's a digit of
int rotate(char plain, int key); // Declare rotate function with input of character to convert and key to convert by

int main(int argc, string argv[])
{
    int key;
    char letter;
    if (argc == 2) // Only run if one argument only after input
    {
        if (only_digits(argv[1])==true) // Check if it's only digit
        {
            key = atoi(argv[1]); // Convert string digit to integer
            string plaintext = get_string("plaintext: "); // User input for text to convert
            printf("ciphertext: "); // Print "ciphertext" per Harvard instructions
            for(int i = 0; i < strlen(plaintext); i++) // Loop to go through every character in input to send to function
            {
                letter = plaintext[i]; // To assign each character to character letter for processing
                // Only run rotate function if the character is a letter, not digit/symbol/space, etc.
                if(isalpha(letter))
                {
                    rotate(letter, key); // Call function
                }
                else
                {
                    printf("%c", letter); // Just print back the digit/symbol if it's a digit/symbol. No need to rotate.
                }
            }
            printf("\n");
            return 0;
        }
        else // If cmd line input not a digit (not valid for key)
        {
            printf("Usage: ./caesar key\n"); // Print error line to describe how it works
            return 1; // Return error
        }
    }
    else
    {
        printf("Usage: ./caesar key\n"); // Error message if more/less than one argument
        return 1; // Error return 1
    }
}

bool only_digits(string argument) // Boolean to check if input is a number per Harvard instructions
{
    char letter;
    int count;
    bool digit=false; // Start by declaring it not a digit
    for(int i = 0; i < strlen(argument); i++) // Loop to go through every character in input
    {
        letter = argument[i]; // Assign each character to letter variable
        if (isdigit(letter)) // If the character is digit
        {
            digit=true; // Change boolean to true
        }
        else // If not a digit
        {
            digit=false; // Change boolean to false
        }
    }
    return digit; // Return true/false
}

int rotate(char plain, int key) // Input the letter and the key (number to rotate)
{
    for(int i = 0; i < key; i++) // Add one at a time, till added the amount specified by key
    {
        plain = plain + 1; // Add one to plain (in accordance with key)
        if(plain == 92) // If plain is 92 (overflow), return to B
        {
            plain = 66;
        }
        else if(plain == 124) // If plain is 124 (overflow), return to b
        {
            plain = 98;
        }
        else if(plain == 91) // If plain is 91 (overflow), return to A
        {
            plain = 65;
        }
        else if(plain == 123) // If plain is 123 (overflow), return to a
        {
            plain = 97;
        }
    }
    printf("%c", plain); // Print the character after every digit in key added
    return 0;
}
