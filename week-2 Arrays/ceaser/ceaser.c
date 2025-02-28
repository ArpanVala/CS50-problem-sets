#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
void encrypt(string plaintext, int key);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./ caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./ caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    encrypt(plaintext, key);
}

bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }

    return true;
}

void encrypt(string plaintext, int key)
{
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            printf("%c", (c - base + key) % 26 + base);
        }
        else
        {
            printf("%c", c);
        }

        /*        OR
        if(isupper(c)){
         printf("%c", (c - 65 + key) % 26 + 65);
        }
        else if(islower(c)){
         printf("%c", (c - 97 + key) % 26 + 97);
        }
        else{
         printf("%c",c);
        }*/
    }
    printf("\n");
}