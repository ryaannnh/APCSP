/*
Objective: To implement a program that calculates the approximate grade level needed to comprehend some text, based on the Coleman-Liau index of text.

Ryan Ho
1/11/2022
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text); // Prototype for function taking string input and outputting integer
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float L = (((float)letters / words) * 100);
    float S = (((float)sentences / words) * 100);
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <16)
    {
        printf("Grade %d\n", index);
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    char letter;
    int lettercount = 0;
    for(int i = 0; i < strlen(text); i++) // Loop to go through every character in input
    {

        letter = text[i]; // All strings are array of chars. Therefore, can use array to reference word[i] and assign to individual char letter for further processing
        if (isalpha(letter))
        {
            lettercount++;
        }
    }
    return lettercount;
}

int count_words(string text)
{
    char letter;
    int wordcount = 1;
    for(int i = 0; i < strlen(text); i++) // Loop to go through every character in input
    {

        letter = text[i]; // All strings are array of chars. Therefore, can use array to reference word[i] and assign to individual char letter for further processing
        if (letter == ' ')
        {
            wordcount++;
        }
    }
    return wordcount;
}

int count_sentences(string text)
{
    char letter;
    int sentencecount = 0;
    for(int i = 0; i < strlen(text); i++) // Loop to go through every character in input
    {

        letter = text[i]; // All strings are array of chars. Therefore, can use array to reference word[i] and assign to individual char letter for further processing
        if (letter == '?' || letter == '.' || letter == '!')
        {
            sentencecount++;
        }
    }
    return sentencecount;
}
