/*
 *  Copyright Balkan Coders, 2019.
 *  Author: Matej Arlović
 *  Date: 23/05/2019.
 */
 
#include <stdio.h>

int fibonacci(int broj);

int main()
{
    int broj;
    printf("Unesite broj: ");
    scanf("%d", &broj);
    printf("Fibonacci niz za broj=%d: %d\n", broj, fibonacci(broj));
    return 0;
}

int fibonacci(int broj)
{
    if(broj == 0 || broj == 1)
    {
        return 1;
    }
    return fibonacci(broj-1) + fibonacci(broj-2);
}
