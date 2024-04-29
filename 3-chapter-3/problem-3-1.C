#include <stdio.h>

int *my_intcpy(int *destination, int *source, int nbr)
{
    int *p = destination;

    for (int i = 0; i < nbr; i++)
    {
        *p++ = *source++;
    }
    return destination;
}

int main(void)
{
    int size = 10;
    int strA[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int strB[10];

    my_intcpy(strB, strA, size);
    
    for (int i = 0; i < size; i++)
    {
        printf("%i", strB[i]);
    }
}