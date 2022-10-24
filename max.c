#include <stdio.h>
#include <cs50.h>

// Function declaration BEFORE the big function
int max(int num1, int num2);

int main()
{
    // Local variable definition
    int ret;
    int a = 0;
    int b = 0;

do{
    printf("Pick the first number:\n");
    scanf("%i", &a);
} while(a - a != 0);

do{
    printf("Pick the second number:\n");
    scanf("%i", &b);
} while(b - b != 0);



    // Calling a function to get max value
    ret = max(a,b);
    if(ret == 0 && a==0 && b==0)
    {
        printf("There is no maximum \n");
    }
    else
    {
        printf("Max value is: %d\n", ret);
    }

    return 0;
}

// Function returning the max between two numbers
// Initializing function, not declaration
// Put initialization UNDER main
int max(int num1, int num2)
{
    // Local variable declaration
    int result;
    if (num1 > num2)
    {
        result = num1;
    }
    else if (num1 < num2)
    {
        result = num2;
    }
    else if (num1 = num2)
    {
        result = num1;
    }
    else
    {
        result = 0;
    }
    return result;
}
