/*
Pseudocode:
Open file with argv
Read file, searching for JPEG header in 512 bytes blocks (fread(data, size, number, inptr))
JPEG header: buffer[0] == 0xff; buffer[1] == 0xd8; buffer[2] == 0xff; (buffer[3] & 0xf0) == 0xe0
If found, keep reading 512 blocks, and write to the new file if NO HEAD. If found head, close file, and reset for new file
Ways: boolean variable to see if hit head or not with true or false, or using while loop and whether first 4 bytes are header

Ryan Ho
27/1/23
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2) // Check for two command line arguments (program name and file name)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    typedef uint8_t BYTE; // Define type called byte for 8 bits (a byte)
    int count = 0; // For determining file name
    int BLOCK_SIZE = 512;
    BYTE buffer[BLOCK_SIZE]; // Create buffer for temporary scanning of 512 character blocks

    FILE *output = NULL; // Output file, first read so NULL
    char *filename = malloc(8 * sizeof(char)); // Create string for holding file name. Alternate: char filename[8]

    if (filename == NULL) // Check if filename allocated properly
    {
        printf("Out of memory.\n");
        return 3;
    }

    FILE *f = fopen(argv[1], "r"); // Open the file named in cmd line with pointer named f in r mode

    if (f == NULL) // Check if file open is successful (check if file exists)
    {
        printf("File open failed. Please try again.\n"); // If NULL, then file open failed.
        return 2;
    }

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, f))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // If JPEG header detected
        {
            if (output != NULL) // Closing output if already opened
            {
                fclose(output);
            }
            //creating the file name
            sprintf(filename, "%03i.jpg", count); // Update into "filename" the number in count with 3 digits.jpg
            output = fopen(filename, "w"); // Create file with filename in writing mode, and link to "output" pointer
            if (output == NULL)
            {
                printf("File creation failed. Please try again.\n");
                return 3;
            }
            count++;
        }
        if (output != NULL) // Check if file creation successful
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output); // If successful, write the buffer onto the output
        }
    }
     // Remove file name for next operation

    if (output != NULL)
    {
        fclose(output);
    }
    fclose(f); // Close input for next operation
    free(filename);

    return 0;
}

