/*
Objective: To write a program that implements a substitution cipher.

Pseudocode:
Check for argc 2
    if strlength(argv[1]) == 26

        Turn cmd line key input into all upper and array upperkey
        Turn cmd line key input into all lower and array lowerkey

        Prompt user for plain text = text

        Print: ciphertext:
        Iterate through each character in text, assign to letter

            if isupper(letter)
                print: upperkey[letter-64]

            else if islower(letter)
                print: lowerkey[letter-96]

            else
                print: letter

    else
        print "Key must contain 26 characters.\n"

11/8/22
Ryan Ho
*/


#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    if (argc == 2) // Only run if one argument only after input
    {
        char upperkey[26], lowerkey[26]; // Declare character arrays for upper and lower key for later use
        string key = 0, text = 0; // Declare string for user inputs key and text
        char keyletter; // For later use in iteration


        if (strlen(argv[1]) != 26) // Error if key input not 26 characters long
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else // If it is 26 characters long
        {
            // Declaration of variables
            int verify[26];
            int alpha = 0, temp = 0;
            key = argv[1];
            for (int j = 0; j < 26; j++) // For loop iteration
            {
                keyletter = key[j]; // Individual letter to be processed in each loop
                upperkey[j] = toupper(keyletter); // To make upper key for later reference, make uppercase and add to upper array
                lowerkey[j] = tolower(keyletter); // To make lower key for later reference, make lowercase and add to lower array

                if isupper(keyletter)
                {
                    temp = keyletter - 65;
                    if (verify[temp] == 1)
                    {
                        return 1;
                    }
                    else
                    {
                        verify[temp]++;
                    }
                }
                if islower(keyletter)
                {
                    temp = keyletter - 97;
                    if (verify[temp] >= 1)
                    {
                        return 1;
                    }
                    else
                    {
                        verify[temp]++;
                    }
                }

                if (isalpha(keyletter))
                {
                    alpha++; // If all characters are alphabet, alpha + 1
                }
            }

            if (alpha == 26) // If no duplicate, all uppercase of A-Z add together should be 2015. Alpha variable should also have 26 if all alphabet
            {
                text = get_string("plaintext: "); // Print prompt
                printf("ciphertext: ");

                char letter; // Declare letter for iteration
                for (int i = 0; i < strlen(text); i++) // For loop to iterate letter and convert
                {
                    letter = text[i]; // Individual character for processing
                    if isupper(letter)
                    {
                        letter = upperkey[letter - 65]; // If uppercase, -65 to convert to number relevant to upperkey array
                    }
                    else if islower(letter)
                    {
                        letter = lowerkey[letter - 97]; // If loewrcase, -97 to convert to number relevant to lowerkey array
                    }
                    printf("%c", letter); // Print converted (or not, if non-alphabet) character
                }
                printf("\n"); // New line at end
            }
            else
            {
                printf("Please ensure there your key only has the alphabet and has no duplicate values.\n"); // If not all alphabet and no repeat, print error message
                return 1; // Error return value
            }
        }
    }
    else
    {
        printf("Usage: ./substitution key\n"); // Error message if no command line input
        return 1;
    }

}
