/*
1)Write a  Program to calculate the sum of first n natural numbers given by the user
 (Example: n=5    sum=1+2+3+4+5)  Pseudocode first
2) Can you write the same with a different kind of loop?
3) if you want to make sure the n is positive and no greater than a 2 bytes number what would you do?

some kind of loop to
    Get number from user (n>1)
    Check if number is positive
for loop from 11 to the number
    sum = sum + num

print out "The sum of all the numbers from 1 to N is"

Ryan Ho
16/09/2022
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Define n, and create flag
    int n; // For number from user
    bool flag=false;  // To prompt number is too small only if failed
        do {
        if (flag){
            printf("Your number is too small. ");
        }
        //Prompt to pick number
        n = get_int("Pick a natural number greater than 2: ");
        flag=true; // Flip bool if number greater than 2
       }
    //Only repeat if n is less than/equal to 2
       while (n <= 2);
    //Define answer variable as 0
          int ans = 0; // Sum of all numbers
           for (int x = 1; x <= n; x ++)
           {
               ans = ans + x; // Loop to calculate sum
           }
                printf("The sum of all the numbers from 1 to %d is %d\n",n,ans);
}
