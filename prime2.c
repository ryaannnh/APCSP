/*
Write an algorithm to determine whether input value is a prime or not.
Pseudocode:
Start
ask user to enter number to check if prime
calculates % modulo of number, If modulo = 0, not prime.
prints whether prime or not
Ryan Ho 28/9/2022
*/


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num;

    do
    {
        num = get_int("Enter a positive number to see if it's prime: "); // Get number from user to check if prime or not
    }
    while (num < 0); // Number must be positive

    if (num == 2)
    {
        printf("%d is a prime number.\n", num); // Is prime number if 2
    }
    else
    {
        for (int i = 2; i < num; i++) // Range for values to find modulo of input with, can start at 2 and can't be greater than the number, i++ each run to divide by different values
        {
            if (num % i == 0)
            {
                printf("%d is not a prime number.\n", num); // If modulo is 0, number is not prime because divisible by integer
                break;
            }
            if (num % i != 0)
            {
                printf("%d is a prime number.\n", num); // If modulo is not 0, number is prime because not divisible by integer
                break;
            }
        }
    }
}
