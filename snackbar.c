
/*
Objective: To write a program that uses structs to calculate the total cost of an order based off a menu

Pseudocode:
Declare struct for item price, name
Input values into array of menu items for both price, name
Print all items on menu and introductory phrase
Ask for user input for food item to add to total
Compare input to menu names array, if matching, return value of price and add to sum
If not matching, print not matching and reprompt
When input blank, print sum of item prices returned

Ryan Ho
30/11/22
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Function Declaration
void add_items(void);
float get_cost(string item);


#define NUM_ITEMS 10 // Define variable as 10

typedef struct // Declaring struct of item and price for menu; Declaring type of menu so no need to repeat struct later
{
    string item;
    float price;
} menu_item;

menu_item menu[NUM_ITEMS]; // Array of menu items within struct, with both item and price.

int main(void)
{
    add_items();

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i]. price); // Printing all items and their prices
    }
    printf("\n");

    float total = 0;
    while (true)
    {
        string item = get_string("Enter a food item: ");
        if (strlen(item) == 0) // If no input
        {
            printf("\n");
            break;
        }

        total += get_cost(item);
    }

    printf("Your total cost is: $%.2f\n", total);
}



// Add items to menu
void add_items(void)
{
    menu[0].item = "burger";
    menu[1].item = "vegan burger";
    menu[2].item = "hot dog";
    menu[3].item = "cheese dog";
    menu[4].item = "fries";
    menu[5].item = "cheese fries";
    menu[6].item = "cold pressed juice";
    menu[7].item = "cold brew";
    menu[8].item = "water";
    menu[9].item = "soda";
    menu[0].price = 9.5;
    menu[1].price = 11;
    menu[2].price = 5;
    menu[3].price = 7;
    menu[4].price = 5;
    menu[5].price = 6;
    menu[6].price = 7;
    menu[7].price = 3;
    menu[8].price = 2;
    menu[9].price = 2;
}

// Calculate total cost
float get_cost(string item)
{
    for(int j = 0; item[j]; j++)
    {
        item[j] = tolower(item[j]); // User input tolower so case doesn't matter
    }
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        if (strcmp (item, menu[i].item) == 0) // Comparing input to menu items
        {
            return menu[i].price; // Return price to add to sum if matching item

        }
    }

    printf("Item not found\n");

    return 0;
}

