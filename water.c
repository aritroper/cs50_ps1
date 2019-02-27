#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("How many minutes do you shower for?\n");
    int minutes = get_int();
    int bottlesOfWater = minutes*12;
    printf("You waste %d ounces of water when you shower.\n", bottlesOfWater);
}