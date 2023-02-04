// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    int factor = atoi(argv[1]);
    // Remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // Read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //START

    int ogpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int ogwidth = bi.biWidth;
    int ogheight = bi.biHeight;
    printf("padding %d",ogpadding);
    bi.biWidth *= factor;
    bi.biHeight *= factor;

    // Determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi.biSizeImage = (((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight));
    bf.bfSize = (bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER));

    // Write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    for (int i = 0; i < abs(ogheight); i++) // To iterate through lines of infile
    {
        for (int z = 0; z < factor; z++) // To repeat each line by factor number before proceed to next line
        {
            int amtseek = ((i*sizeof(RGBTRIPLE)*(ogpadding + abs(ogwidth))) + 54); // To set where to seek for each repetition, addressing for header, original padding and original width
            fseek(inptr, amtseek, SEEK_SET);

            for (int j = 0; j < abs(ogwidth); j++)
            {
                RGBTRIPLE temp; // Temporary storage to store RGB
                fread(&temp, sizeof(RGBTRIPLE), 1, inptr); // Store RGB data to temp, required to add & for fread
                for (int n = 0 ; n < factor; n++)
                {
                    fwrite(&temp, sizeof(RGBTRIPLE), 1, outptr); // Writing to output file
                }
            }
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr); // Write outfile padding
            }

        }

    }

    // Close infile
    fclose(inptr);

    // Close outfile
    fclose(outptr);

    // Success
    return 0;
}
