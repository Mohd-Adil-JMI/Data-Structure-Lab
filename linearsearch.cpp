#include <iostream>
using namespace std;

int linearsearch(int arr[], int key)
{
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int arr[10] = {2, 1, 3, 5, 7, 10, 14, 15, 8, 4};
    cout<<linearsearch(arr, 4);

    return 0;
}