/*
Date : 13/04/2021
Obj : Program to input a dataword and output codeword with even parity bit.
Auther : Yuvraj Raghuvanshi (https://github.com/yuvrajraghuvanshis)
*/

#include <stdio.h>
#include <iostream>

struct dataword_codeword
{
    int dataword, codeword, parity;
};

char CountNumberOf1S(int num)
{
    int rem, count = 0;
    while (num > 0)
    {
        rem = num % 10;
        if (rem == 1)
            count++;
        num /= 10;
    }

    return count % 2 == 0 ? 0 : 1;
}

int AppendParityToCodeword(int dataword, int parity)
{
    if (parity == 0)
    {
        return dataword * 10;
    }
    else
    {
        return dataword * 10 + 1;
    }
}

int main()
{
    int dn, i, temp;
    struct dataword_codeword dc[10] = {};
    printf("Enter the number of datawords : ");
    scanf("%d", &dn);
    printf("Enter datawords : ");
    // Enter dataword and it's parity...
    for (i = 0; i < dn; i++)
    {
        scanf("%d", &temp);
        dc[i].dataword = temp;
        dc[i].parity = CountNumberOf1S(temp);
    }

    // Enter codeword and it's parity...
    for (i = 0; i < dn; i++)
    {
        dc[i].codeword = AppendParityToCodeword(dc[i].dataword, dc[i].parity);
    }

    printf("DW\tCW\tP(DW)");
    for (i = 0; i < dn; i++)
    {
        printf("\n%d\t%d\t%d", dc[i].dataword, dc[i].codeword, dc[i].parity);
    }

    printf("\n");
    system("pause"); // To freeze screen.
    return 0;
}