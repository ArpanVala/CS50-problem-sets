#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num;
    int temp;
    do
    {
        num = get_int("Height: ");
    } while (num < 1 || num > 8);
    temp = num;

    for (int row = 0; row < num; row++)
    {
        while ((temp - row) - 1 > 0)
        {
            printf(" ");
            temp--;
        }
        for (int col = 0; col <= row; col++)
        {
            printf("#");
        }
        printf("  ");
        for (int col = 0; col <= row; col++)
        {
            printf("#");
        }
        printf("\n");
        temp = num;
    }
}