#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_score(string str);

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Prompt the user for two words
    string strOne = get_string("Player 1: ");
    string strTwo = get_string("Player 2: ");

    string winner = "tie!";

    // Compute the score of each word
    int score1 = get_score(strOne);
    int score2 = get_score(strTwo);

    // Print the winner
    if (score1 > score2)
    {
        winner = "Player 1 wins!";
    }
    else if (score2 > score1)
    {
        winner = "Player 2 wins!";
    }
    printf("%s\n", winner);
}

int get_score(string str)
{
    int score = 0;

    for (int i = 0, len = strlen(str); i < len; i++)
    {
        // Check if it's a letter
        if (isalpha(str[i]))
        {
            // convert all leters to lower case
            char lower = tolower(str[i]);

            score += POINTS[lower - 97];
        }
        //          OR
        // if (isupper(str[i]))
        // {
        //     score += POINTS[str[i] - 'A'];
        // }
        // else if (islower(str[i]))
        // {
        //     score += POINTS[str[i] - 'a'];
        // }
    }
    return score;
}