#include <stdio.h>

void printfunc(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void BubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        printf("Iteration: %d\n", i + 1);

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            printfunc(arr, n);
            printf("\n");
        }
    }
}

void BubbleSortEarlyTermination(int arr[], int n)
{
    int i, j, f = 1;
    for (i = 0; i < n - 1; i++)
    {
        f = 1;
        printf("Iteration: %d\n", i + 1);
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                f = 0;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            printfunc(arr, n);
            printf("\n");
        }

        if (f == 1)
        {
            printf("Array is sorted!\n");
            break;
        }
    }
}

int main()
{
    int arr[100], n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    BubbleSort(arr, n);
    BubbleSortEarlyTermination(arr, n);

    return 0;
}