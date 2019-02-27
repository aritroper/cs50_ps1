#include <stdio.h>
#include <math.h>
#include <cs50.h>


int digitCount(long card)
{
    if (card == 0)
    {
        return 1;
    }

    int n = 0;
    while (card)
    {
        card /= 10;
        n++;
    }
    return n;
}

bool checkSum(long card)
{
    long divider = 10;
    long sum1 = 0;
    long sum2 = 0;

    //1. get every other digit of card starting at index 1
    //2. multiply each digit by 2
    //3. add these digits (i.e. 14 becomes 1+4)
    for (long i = 1; i < digitCount(card); i += 2)
    {
        long digit = (card / divider) % 10;
        digit = digit * 2;
        if (digit >= 10)
        {
            int newDigit = 0;
            while (digit > 0)
            {
                newDigit += digit % 10;
                digit /= 10;
            }
            digit = newDigit;
        }
        sum1 += digit;
        divider = divider * 100;
    }

    divider = 1;

    //get sum of every other digit starting at index 1
    for (long i = 0; i < digitCount(card); i += 2)
    {
        long digit = (card / divider) % 10;
        sum2 += digit;
        divider = divider * 100;
    }

    printf("%li\n", sum1);
    printf("%li\n", sum2);
    int sumCheck = (sum1 + sum2) % 10;

    if (sumCheck == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getFirstTwoDigits(long card)
{
    int number = card / pow(10, (digitCount(card) - 2));
    return number;
}

int main(void)
{
    printf("Enter your credit card number?\n");
    long card = get_long_long();
    if (checkSum(card))
    {
        if ((getFirstTwoDigits(card) == 34 || getFirstTwoDigits(card) == 37) && digitCount(card) == 15)
        {
            printf("AMEX\n");
        }
        else if ((getFirstTwoDigits(card) >= 40 && getFirstTwoDigits(card) <= 50) && (digitCount(card) == 13 || digitCount(card) == 16))
        {
            printf("VISA\n");
        }
        else if ((getFirstTwoDigits(card) >= 51 && getFirstTwoDigits(card) <= 55) && digitCount(card) == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
