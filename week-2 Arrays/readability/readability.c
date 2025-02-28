#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void countTextData(string str);
int colemanLiauindex();

int words, letters, sentences;

int main(int argc, string argv[])
{

    // Prompt the user for some text
    string text = get_string("text: ");

    // Count the number of letters, words, and sentences in the text
    countTextData(text);

    // Compute the Coleman-Liau index
    int index = colemanLiauindex();

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

void countTextData(string str)
{
    letters = 0;
    words = 1;
    sentences = 0;
    for (int i = 0, len = strlen(str); i < len; i++)
    {
        if (isalpha(str[i]))
        {
            letters++;
        }

        if (str[i] == ' ')
        {
            words++;
        }

        if (str[i] == '?' || str[i] == '!' || str[i] == '.')
        {
            sentences++;
        }
    }
}

int colemanLiauindex()
{
    float L = (float)letters / (float)words * 100.0;
    float S = (float)sentences / (float)words * 100.0;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}