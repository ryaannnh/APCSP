#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i<height; i++)
    {
        for (int k = 0; k<width; k++)
        {
            BYTE avg = 0; // Initialize avg variable to calculate average of rgb to change to greyscale
            avg = round((image[i][k].rgbtBlue + image[i][k].rgbtRed + image[i][k].rgbtGreen)/3.0); // Calculation of rgb by sum and division
            image[i][k].rgbtBlue = avg; // Updating rgb variables with average
            image[i][k].rgbtRed = avg;
            image[i][k].rgbtGreen = avg;
        }
    }

    return;
}

// Convert image to sepia

/*
1) With nested for loop:
2) Initialize BYTE variables originalR/G/B and sepiaR/G/B
3) Assign rgbtR/G/B from double array to variable originalR/G/B
4) Use algorithm to calculate sepiaR/G/B from originalR/G/B
5) Check if sepiaR/G/B >255. If yes, assign 255 instead of value
5) Assign sepiaR/G/B to double array values

*/
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i<height; i++)
    {
        for (int k = 0; k<width; k++)
        {
            BYTE originalR = image[i][k].rgbtRed;
            BYTE originalG = image[i][k].rgbtGreen;
            BYTE originalB = image[i][k].rgbtBlue;

            int sepiaR = round(.393 * originalR + .769 * originalG + .189 * originalB);
            int sepiaG = round(.349 * originalR + .686 * originalG + .168 * originalB);
            int sepiaB = round(.272 * originalR + .534 * originalG + .131 * originalB);

            if (sepiaR > 255)
            {
                image[i][k].rgbtRed = 255;
            }
            else
            {
                image[i][k].rgbtRed = sepiaR;
            }

            if (sepiaG > 255)
            {
                image[i][k].rgbtGreen = 255;
            }
            else
            {
                image[i][k].rgbtGreen = sepiaG;
            }

            if (sepiaB > 255)
            {
                image[i][k].rgbtBlue = 255;
            }
            else
            {
                image[i][k].rgbtBlue = sepiaB;
            }
        }
    }

    return;
}

// Reflect image horizontally

/*
Pseudocode:
Nested for loop
Temp BYTE variable, assign image[i][k] to it
image[i][k] replaced by image[width-i][k], for loop until i reaches width/2

*/
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < (width+1)/2; k++)
        {
            BYTE temp = 0;
            temp = image[i][k].rgbtBlue;
            image[i][k].rgbtBlue = image[i][width-(k+1)].rgbtBlue;
            image[i][width-(k+1)].rgbtBlue = temp;

            temp = image[i][k].rgbtRed;
            image[i][k].rgbtRed = image[i][width-(k+1)].rgbtRed;
            image[i][width-(k+1)].rgbtRed = temp;

            temp = image[i][k].rgbtGreen;
            image[i][k].rgbtGreen = image[i][width-(k+1)].rgbtGreen;
            image[i][width-(k+1)].rgbtGreen = temp;
        }
    }
    return;
}

// Blur image

/*
First create a copy of the 2d array with nested for loop
Initialize variables totalRed/totalGreen/totalBlue to store average of red, blue, and green
Nested for loop to calculate average, starting from i/k = -1 until 1
Check validity of neighboring box with if to see whether i-1 or +1 will be outside edge (seeing if the result will be less than 0 or more than width/height)
Another nested for loop, variables j and l
Find neighboring box with image: image[l+k][j+i]
Add number counter to check how many operations done for calculating average
Calculate average, update original 2d array
*/

void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE image2[height][width]; // For image copy

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            image2[i][k].rgbtBlue = image[i][k].rgbtBlue;
            image2[i][k].rgbtRed = image[i][k].rgbtRed;
            image2[i][k].rgbtGreen = image[i][k].rgbtGreen;
        }
    }

    float totalRed = 0;
    float totalGreen = 0;
    float totalBlue = 0;
    float counter = 0;


    for (int j = 0; j < height; j++)
    {
        for (int l = 0; l < width; l++)
        {
            totalRed = totalGreen = totalBlue = counter = 0; // Resetting variables to calculate average

            if ((0 <= (j-1)) && ((j-1)< height) && (0 <= (l-1)) && ((l-1) < width)) // Top left
            {
                totalBlue += image2[j-1][l-1].rgbtBlue;
                totalRed += image2[j-1][l-1].rgbtRed;
                totalGreen += image2[j-1][l-1].rgbtGreen;
                counter ++;
            }
            if ((0 <= (j+1)) && ((j+1)< height) && (0 <= (l-1)) && ((l-1) < width)) // Bottom left
            {
                totalBlue += image2[j+1][l-1].rgbtBlue;
                totalRed += image2[j+1][l-1].rgbtRed;
                totalGreen += image2[j+1][l-1].rgbtGreen;
                counter ++;
            }
            if ((0 <= (j-1)) && ((j-1)< height) && (0 <= (l+1)) && ((l+1) < width)) // Top right
            {
                totalBlue += image2[j-1][l+1].rgbtBlue;
                totalRed += image2[j-1][l+1].rgbtRed;
                totalGreen += image2[j-1][l+1].rgbtGreen;
                counter ++;
            }
            if ((0 <= (j+1)) && ((j+1)< height) && (0 <= (l+1)) && ((l+1) < width)) // Bottom right
            {
                totalBlue += image2[j+1][l+1].rgbtBlue;
                totalRed += image2[j+1][l+1].rgbtRed;
                totalGreen += image2[j+1][l+1].rgbtGreen;
                counter ++;
            }
            if ((0 <= (j-1)) && ((j-1)< height)) // Top center
            {
                totalBlue += image2[j-1][l].rgbtBlue;
                totalRed += image2[j-1][l].rgbtRed;
                totalGreen += image2[j-1][l].rgbtGreen;
                counter ++;
            }
            if ((0 <= (j+1)) && ((j+1)< height)) // Bottom center
            {
                totalBlue += image2[j+1][l].rgbtBlue;
                totalRed += image2[j+1][l].rgbtRed;
                totalGreen += image2[j+1][l].rgbtGreen;
                counter ++;
            }
            if ((0 <= (l-1)) && ((l-1) < width)) // Mid left
            {
                totalBlue += image2[j][l-1].rgbtBlue;
                totalRed += image2[j][l-1].rgbtRed;
                totalGreen += image2[j][l-1].rgbtGreen;
                counter ++;
            }
            if ((0 <= (l+1)) && ((l+1) < width)) // Mid right
            {
                totalBlue += image2[j][l+1].rgbtBlue;
                totalRed += image2[j][l+1].rgbtRed;
                totalGreen += image2[j][l+1].rgbtGreen;
                counter ++;
            }

            // Adding the center itself to the total
            totalBlue += image2[j][l].rgbtBlue;
            totalRed += image2[j][l].rgbtRed;
            totalGreen += image2[j][l].rgbtGreen;
            counter ++;

            // Calculate average
            totalBlue = round((float)totalBlue/counter);
            totalGreen = round((float)totalGreen/counter);
            totalRed = round((float)totalRed/counter);

            // Update image array
            image[j][l].rgbtRed = totalRed;
            image[j][l].rgbtGreen = totalGreen;
            image[j][l].rgbtBlue = totalBlue;
        }
    }


    return;
}
