#include <stdio.h>
#include <cs50.h>

int main(void)
{
    bool correctInput = false;
    int height = 0;
//checks if input is positive number below 24
    while (correctInput == false)
    {
        //gets user input
        printf("Height?\n");
        height = get_int();
        if (height >= 0 && height < 24)
        {
            correctInput = true;
        }
    }
//prints pyramid
    for (int i = 0; i < height; i++)
    {
        for (int j = height; j > i + 1; j--)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}