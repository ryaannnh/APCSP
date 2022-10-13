/*
Program to determine whether credit card number is valid, and it's type— Luhn's Algorithm.
Multiply very other digit by 2, starting with the number’s second-to-last digit. Then, find sum of these numbers' digits (12, 5 = 1+2+5)
Add the result to sum of all numbers not multiplied by 2
If modulo 10 of result = 0, valid credit card number
To find credit card company, check first numbers of sequence:
MSTR: 51, 52, 53, 54, or 55 / VISA: 4 / AMEX: 34/37
Pseudocode:
Do while loop to get user input of card number until positive
Introduce num variable, which is updated with the needed value of credit card number
While loop to divide card number by 10, then modulo 10 to find last number alternatingly
    Sum variable for calculation
    If number is larger than 9, sum += num %10
    Else, sum += num
    Card/100
While loop to determine sum of remaining numbers
    Sum1 variable
    sum = num1 + sum1 after card1/10
For loop for length - 2 times of cardno/10 to get starting 2 digits
11/10/22
Ryan HO
*/

#include <cs50.h>
#include <stdio.h>

long get_cardno(void);
long sum_of_multiple(long cardno); // Declare function for finding sum of multiples
long sum_of_remaining(long cardno); // Declare function for finding sum of remaining digits
long card_length (long cardno); // Declare function for finding card length
long start_digits (long cardno, long length); // Declare function for finding starting digits

int main(void)
{
    long cardno = get_cardno(); // Call function to get user's card number + assign to variable
    long mul_sum = sum_of_multiple(cardno); // Call function with cardno input to find sum of multiple
    long rem_sum = sum_of_remaining(cardno); // Call function to find sum of remaining values
    long length = card_length(cardno); // Calculate card length
    long total_sum = mul_sum + rem_sum; // Calculates total of two sums above
    long start = start_digits(cardno, length); // Call function to find starting digits

    if (total_sum % 10 != 0) // Given by problem. Invalid if the last number of total sum ≠ 0
    {
        printf("INVALID\n");
    }
    else if (length > 16 || length == 14) // Number must be 13/15/16 digits long
    {
        printf("INVALID\n");
    }
    else if (length == 13 && start >= 40 && start <= 49) // Length 13 is always Visa if starts with 4
    {
        printf("VISA\n");
    }
    else if (length == 16 && start >= 40 && start <= 49) // Length 16 is Visa if starts with 4
    {
        printf("VISA\n");
    }
    else if (length == 15 && start == 34)// Length 15 is  Amex, if start with 34/37
    {
        printf("AMEX\n");
    }
     else if (length == 15 && start == 37)// Length 15 is  Amex, if start with 34/37
    {
        printf("AMEX\n");
    }
    else if (start >= 51 && start <= 55) // Start with 51-55 are Mastercard
    {
         printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n"); // Anything else invalid
    }

}


long get_cardno(void)
{
    long cardno;
    do
    {
        cardno = get_long("Enter your credit card number: ");
    } while (cardno < 0); // Check number is 13 digits or above
    return cardno;
}

long sum_of_multiple(long cardno)
{
    long num, sum = 0, card = 0; // Declare variables
    card = cardno / 10; // First round before loop, shift one digit from back first
    num = card % 10 * 2; // Find last digit multiplied by two
    if (num > 9) // Split product if double digit
    {
        sum = sum + num % 10; // Ones digit, adding to sum
        sum = sum + num / 10; // Tens digit, adding to sum
    }
    else
    {
        sum = sum + num; // If single digit number, simply add to sum
    }

    while (card > 1) // Loop until goes through entire card number
    {
        card = card / 100; // Alternate digits
        num = card % 10 * 2;
        if (num > 9)
        {
            sum = sum + num % 10;
            sum = sum + num / 10;
        }
        else
        {
            sum = sum + num;
        }
    }
    return sum;
}

long sum_of_remaining(long cardno)
{
    long num1, sum1 = 0, card1 = 0; // Declare values
    card1 = cardno;
    num1 = card1 % 10; // Start first before looping
    sum1 = sum1 + num1;

    while (card1 > 1) // Goes through entire card number
    {
        card1 = card1 / 100; // Alternate digits
        num1 = card1 % 10; // Modulo 10 to find last number
        sum1 = sum1 + num1; // Add last number to sum
    }
    return sum1;
}

long card_length(long cardno)
{
    long length = 0; // Declare variables
    long cardno2 = cardno;
    while(cardno2 > 0) // Until no more values in cardno2
    {
        cardno2 = cardno2 / 10; // Remove last value
        length++; // Length counter +1
    }
    return length;
}

long start_digits(long cardno, long length)
{
    long cardno3 = cardno; // Declare variables
    long length3 = length;
    for (int i = 0; i < length - 2; i++) // For loop, for the length - 2 times to leave 2 digits
    {
        cardno3 = cardno3 / 10; // Remove last digit by / 10
    }
    return cardno3;
}
