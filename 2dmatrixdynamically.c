#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **ptr;
    ptr = (int **)malloc(3 * sizeof(int*));
    ptr[0] = (int *)malloc(4 * sizeof(int));
    ptr[1] = (int *)malloc(4 * sizeof(int));
    ptr[2] = (int *)malloc(4 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%u\n", ptr);
            ptr++;
        }
    }

    return 0;
}