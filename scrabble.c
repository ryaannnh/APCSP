/*
Compare inputs from two users according to Scrabble scores. Uses string, char, array, and various string functions.

Pseudocode:
Convert input to all uppercase as CHAR

Compare score to see which one is higher value
    If score1>score2, P1 wins
    If score2>score1, P2 wins

Calculate score
    Deduct 65 from uppercase char, ends up with A/B/C... as 0/1/2; assign to array
    Iterate through the points array with the values above and calculate sum of points for each user input


24/10/22
Ryan Ho
*/

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1); // Assign returned sum of points to score1
    int score2 = compute_score(word2); // Assign returned sum of points to score2

    // TODO: Print the winner
    if(score1 > score2) // If P1 has higher score than P2, P1 wins.
    {
        printf("Winner is player 1!\n");
    }
    else if(score2 > score1) // If P2 has higher score than P1, P2 wins.
    {
        printf("Winner is player 2!\n");
    }
    else // If P1&P2 have equal score, it is tie.
    {
        printf("Tie!")
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int points = 0; // Declare variable for points sum
    for(int i = 0; i < strlen(word); i++) // Loop for number of characters in input
    {
        char letter = toupper(word[i]); // All strings are array of chars. Therefore, can use array to reference word[i] and assign to individual char letter for further processing
        if (isalpha(letter)){
            points = points + POINTS[letter-65]; // Because char is a value in ASCII, and A in ASCII is 65, to find the relevant value in POINT array is done by the letter-65. If letter is A, result would be 0. If B, result 1, etc.
        }
    }
    return points; // Return sum of points
}
