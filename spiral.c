/**
 * Copyright © 2020
 * Title: Hollow Spiral Pattern
 * Author: Mr. Rabbit / Tsubasa
 * */



#include <stdio.h>

int main(int argc, char *argv[])
{
    int size = 0;
    printf("Enter size: "); scanf("%d", &size);
    
    char spiral[size - 3][size];
    int row = size - 2, col = size;
    printf("\n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            spiral[i][j] = ' ';
    }

    for (int i = 0; i < size; i += 2)
    {
        for (int j = i; j < (col - i); j++)
            spiral[i][j] = '*';

        for (int j = (i + 1); j <= (col - i - 3); j++)
            spiral[j][col - i - 1] = '*';

        for (int j = (col - i - 2); j > (i + 1); j--)
            spiral[col - i - 3][j] = '*';

        for (int j = col - i - 4; j > (i + 1); j--)
            spiral[j][i + 2] = '*';

    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)    
            printf("%c ", spiral[i][j]);

        printf("\n");
    }

    return 0;
}