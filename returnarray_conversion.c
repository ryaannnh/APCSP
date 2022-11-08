/*
Write a program that will convert a Decimal Number to Binary, Octal, and Hexadecimal.
Make a function for each conversion, and use arrays to save the conversion in the right order then print the conversion.

Allow the user to convert another number when you are done with the first one.

ex.
Input:
129

Output:
129 Conversion to:
Binary: 10000001
Octal:   201
Hex:     81

Pseudocode:
Declare functions of:
    1. User input of conversion number
    2. Binary conversion
    3. Octal conversion
    4. Hex conversion
Main function
    Call functions

numInput function - User input of conversion number
    int num = get_int(prompt)
    print "*num* conversion to:"

Binary conversion (send number)
    Make array named binaryNum
    For loop to repeat and store num%2 in array (num = num/2 after each)
    For loop to print binary result in reverse

Octal conversion
    Make array named octalNum
    For loop to repeat and store num%8 in array (num = num/8 after each)
    For loop to print octal result in reverse

Hex conversion
    Make array named hexNum
    For loop to repeat and store num%16 in array (num = num/16 after each)
    For loop through every value in array
        If hexNum[i] = 10, hexNum[i] = A
        Else if hexNum[i] = 11, hexNum[i] = B
        Else if hexNum[i] = 12, hexNum[i] = C
        Else if hexNum[i] = 13, hexNum[i] = D
        Else if hexNum[i] = 14, hexNum[i] = E
        Else if hexNum[i] = 15, hexNum[i] = F

    For loop to print hex result in reverse

18/10/22
Ryan Ho
*/

#include <stdio.h>
#include <cs50.h>

// Declare functions
int numInput (void);
int baseInput (void);

char * Convert (int num, int base); // Note the pointer *



int main(void)
{
    int num;
    int repeat;
    int base;
    char * convertedarray; // Pointer declaration for convertedarray
    do // Do while loop to repeat if user requests
    {

        num = numInput();
        base = baseInput();
        printf("%i conversion to base %i: \n", num, base);
        convertedarray = Convert(num, base); // Assign returned value to convertedarray already declared as pointer
        for (int k = 0; k < 999; k++) // For loop to print returned array
        {
            printf("%c", convertedarray[k]); // Print every characters in converted array
        }
        printf("\n");
        repeat = get_int ("Would you like to convert another number? Enter 1 for YES, 0 for NO: ");
    } while (repeat == 1);


}

int numInput (void)
{
    int num;
    do
    {
        num = get_int("Enter number to be converted: ");
    } while (num < 0);
    return num;
}

int baseInput (void)
{
    int base;
    do
    {
        base = get_int("What base would you like to convert to: "); //
    } while (base < 0);
    return base;
}

char * Convert (int num, int base) // Function for decimal to binary (note the pointer *)
{
    int Num[999]; // Declare array
    static char Result[999]; // Must be static char to be returned
    int len = 0; // Declare len variable for length
    for(len = 0; num > 0; len++) // For loop to update array with modulo 2 of input
    {
        Num[len] = num % base;
        num = num / base; // Update num for future loops
    }

    char menu[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}; // Declare menu array and their variables

    int j = 0; // Declare and initialize j variable
    for(int i = len - 1; i >= 0; i--) // Add number in reverse order to array
    {
        Result[j] = menu[Num[i]]; // Update array with reversed results
        j++; // J ++ to track array
    }

    return (Result); // Return array
}
