#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        for (int i = x; i <= y; i++)
        {
            bool flag = true;
            if (i == 1)
            {
                flag = false;
            }

            for (int j = 2; j <= pow(i, .5); j++)
            {
                if (i % j == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}