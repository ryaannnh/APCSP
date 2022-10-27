/*
Check that a password has at least one lowercase letter, uppercase letter, number and symbol
Practice iterating through a string
Practice using the ctype library

Pseudocode:
Use given function and ASCII versions of each letter to iterate through password input and check to see if each character is in range of upper/lower/symbol/number of ASCII table.
If either is true, change int variable of each character type to 1 to indicate presence.
Boolean return true if all four character types 1, else return false.

26/10/22
Ryan HO
*/



#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int upper, lower, symbol, number = 0;
    char letter;
    for(int i = 0; i < strlen(password); i++) // Loop to go through every character in input
    {

        letter = password[i]; // All strings are array of chars. Therefore, can use array to reference word[i] and assign to individual char letter for further processing
        if (isalpha(letter))
        {
            if (letter >= 65 && letter <= 90)
            {
                upper = 1; // If ASCII shows uppercase number, make upper variable into 1 to show there is uppercase
            }
            else if (letter >= 97 && letter <= 122)
            {
                lower = 1; // If ASCII of letter is lowercase range, make lower variable into 1 to show valid
            }
        }
        else if ((letter >= 33 && letter <= 47) || (letter >= 58 && letter <= 64) || (letter >= 91 && letter <= 96) || (letter >= 123 && letter <= 126))
        {
            symbol = 1; // If ASCII is symbol range, make symbol variable into 1
        }
        else if (letter >= 48 && letter <= 57)
        {
            number = 1; // If ASCII is number range, make number variable into 1
        }
    }

    if (number == 1 && upper == 1 && lower == 1 && symbol == 1) // If all four character types are present
    {
        return true; // Return boolean true to output verified password string
    }
    else
    {
        return false; // Return false if not all character types present
    }
}
