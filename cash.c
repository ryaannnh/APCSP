/*
Task: To calculate the minimum amount of coins (pennies, nickels, dimes, quarters) needed to return a change (inputted by user in cents).
Pseudocode:
get_int to receive user input for amount of cents to return change for
Make functions for calculating quarters, dimes, nickels, and pennies to return
In the code, call the first function for calculating quarters. After finding the number of quarters, deduct the amount that has been accounted by frmo the cents, to accomodate for future calculations
Repeat for dimes, nickels, and pennies
Find sum of quarters, dimes, nickels, pennies
Print sum which represents minimum # of coins needed to return the change
10/10/22
Ryan HO
*/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents = get_cents(); // Call function to ask how many cents the customer is owed

    int quarters = calculate_quarters(cents); // Call functions for number of quarters to return
    cents = cents - quarters * 25; // Update cents value by removing amount covered by quarters, so following calculations don't repeat the change already given

    int dimes = calculate_dimes(cents); // Call functions for number of dimes to return
    cents = cents - dimes * 10; // Remove amount covered by dimes from cent value

    int nickels = calculate_nickels(cents); // Call functions for number of nickels to return
    cents = cents - nickels * 5; // Remove amount covered by nickels from cent value

    int pennies = calculate_pennies(cents); // Call function for number of pennies to return
    cents = cents - pennies * 1; // Remove amount covered by pennies from cent value

    int coins = quarters + dimes + nickels + pennies; // Find sum of number of coins to return

    printf("%i\n", coins); // Print coins value, which is the sum of number of coins to include
}

int get_cents(void)
{
    int change;
    do
    {
        change = get_int("Change owed: "); // User input amount (in cents) for change
    } while(change < 0); // Reject until positive number (greater than 0)

    return change; // Returns change for code to calculate
}

int calculate_quarters(int cents)
{
    double quarterno = cents / 25;
    quarterno = floor(quarterno); // Floor result of number of quarters, because a result of e.g. 3.64 does not mean 4 quarters which int would result. Instead, only complete integers meaning the result should be 3 - which we can accomplish with a double that is floored.

    return quarterno;
}

int calculate_dimes(int cents)
{
    double dimeno = cents / 10; // Same reasoning as for quarters. New dimeno to calculate amount that can be filled with cents. Note that cent at this point would already be changed by code on top to have removed quarters already, so no need to worry about that.
    dimeno = floor(dimeno);

    return dimeno;
}

int calculate_nickels(int cents)
{
    double nickelno = cents / 5;
    nickelno = floor(nickelno);

    return nickelno; // Returning the result we calculated for nickels we need.
}

int calculate_pennies(int cents)
{
    double pennyno = cents / 1;
    pennyno = floor(pennyno);

    return pennyno; // Same reasoning as quarters/dimes/nickels.
}
