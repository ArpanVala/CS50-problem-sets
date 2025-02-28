#include <cs50.h>
#include <stdio.h>

int main()
{
    // prompt user for change owed, in cents
    int cents, coins = 0;
    do
    {
        cents = get_int("Change owed: ");
    } while (cents < 0);

    // Calculate how many quarters you should give customer
    coins = coins + cents / 25;
    // Subtract the value of those quarters from cents
    cents = cents % 25;

    // Calculate how many dime you should give customer
    coins = coins + cents / 10;
    cents = cents % 10;

    // Calculate how many nickels you should give customer
    coins = coins + cents / 5;
    cents = cents % 5;

    // Calculate how many penny you should give customer
    coins = coins + cents;

    printf("%i\n", coins);
}