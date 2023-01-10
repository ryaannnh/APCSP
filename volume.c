/*
Objective: File reading program that modifies volume of .wav file that has 44 initial bytes as header and the remaining in pairs of data that should be modified according to the factor.

Pseudocode:
Copy first 44 bytes of input file to output file by using uint8_t filetype which is 1 byte
Read 44 elements of uint8_t type, then store in array called header of size 44
Write the contents in header array to the output file
Create buffer of the type int16_t which is sized 2 bytes
Multiply the contents of buffer by the factor, which makes the .wav louder or softer
Write the contents in buffer to the output file
Repeat until no lines are left by using while loop of fread

Ryan Ho
10/11/22
*/

// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) // Checking if input pointer is valid, to prevent problems later
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]); // String to float, because everyting from cmd line is string (even numbers)

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE]; // Array of type uint8_t with the size of 44 (header_size)
    fread(header, sizeof(uint8_t), HEADER_SIZE, input); // Read the first 44 bytes of input into the array header - (array name, bytes of each element, number of elements, input file name)
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output); // Format same as fread except last file represents output file name

    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer; // Buffer that needs 2 bytes only to store in pairs
    while (fread(&buffer, sizeof(int16_t), 1, input)) // Temporarily store the value of first two bytes of input at buffer
    {
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(int16_t), 1, output); // Write the updated buffer value to the output file
    }

    // Close files
    fclose(input);
    fclose(output);
}
