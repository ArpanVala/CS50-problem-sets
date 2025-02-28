#include <cs50.h>
#include <stdio.h>

int main()
{
    int num;
    int temp;
    do
    {
        num = get_int("Height: ");
        temp = num;
    } while (num < 1);

    for (int i = 0; i < num; i++)
    {
        while ((temp - i) - 1 > 0)
        {
            printf(" ");
            temp--;
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
        temp = num;
    }
}