#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main()
{

    // This pointer will hold the base address of the block created
    int* ptr;
    int n, i;

    // Get the number of elements for the array
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Entered number of elements: %d\n", n);

    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));

    // Check if the memory has been successfully allocated by memory because of multiple factors
    if (ptr == NULL) { // If failed to allocate, pointer would be null
        printf("Memory not allocated.\n");
        exit(0); // Exit program if memory allocation failed
    }
    else {

        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");

        // If you want to put values into the memory, use array and pointers and for loop
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
        printf("\n\n");

    }

    int* ptrr; // Making new pointer
    int k;

    int j = get_int("Enter number of elements: "); // Number of elements desired in variable j
    printf("Entered number of elements: %d\n", j); // Printing j for user to confirm

    // Calloc to initialize the desired number of elements in the size of int
    ptrr = (int*)calloc(j, sizeof(int));

    // Check if the memory has been successfully allocated by memory because of multiple factors
    if (ptrr == NULL) // If failed to allocate, pointer would be null
    {
        printf("Memory not allocated.\n");
        exit(0); // Exit program if memory allocation failed
    }
    else // If not null, then memory has been successfully allocated
    {
        printf("Memory successfully allocated using calloc.\n");

        for (k = 0; k < j; ++k) // To put values into the memory with array, pointer and for loop. k<j ensures stops before last element is reached
        {
            ptrr[k] = k + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (k = 0; k < j; ++k)
        {
            printf("%d, ", ptrr[k]);
        }

        printf("\n\n");
    }

    free(ptr); // Freeing the ptr memory

    int z = get_int("Pick a new size for ptrr: ");

    ptrr = realloc(ptrr, z * sizeof(int)); // Dynamically re-allocate ptrr with realloc() to size of new input


    if (ptrr == NULL) // If failed to allocate, pointer would be null
    {
        printf("Memory not allocated.\n");
        exit(0); // Exit program if memory allocation failed
    }
    else // If not null, then memory has been successfully allocated
    {
        printf("Memory successfully re-allocated using realloc.\n");

        for (int m = 0; m < z; ++m) // To put values into the memory with array, pointer and for loop. k<j ensures stops before last element is reached
        {
            ptrr[m] = m + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (int m = 0; m < z; ++m)
        {
            printf("%d, ", ptrr[m]);
        }

        printf("\n\n");
    }


    return 0; // Free the memory
}
