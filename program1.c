#include <stdio.h>
#include <stdlib.h>
int factorial(int n)
{
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        f = f * i;
    }
    return f;
}
int SumN(int n)
{
    int sum = 0;
    printf("The series is :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", i + 1);
        sum += i + 1;
    }
    printf("\n");
    return sum;
}
void fibonacci()
{
    int sum = 0, n;
    int a = 0;
    int b = 1;
    printf("Enter the value upto which Fibonacci series is to be printed: ");
    scanf("%d", &n);
    printf("Fibonacci series: ");

    while (sum <= n)
    {
        printf("%d ", sum);
        a = b;
        b = sum;
        sum = a + b;
    }
}
int power(int a, int b)
{
    int pow = 1;
    for (int i = 1; i <= b; i++)
    {
        pow = pow * a;
    }
    return pow;
}

int main()
{
    while (1)
    {
        int ch;
        printf("Enter 1 for Factorial\n");
        printf("Enter 2 for Sum of Series of natural number upto n terms\n");
        printf("Enter 3 for Fibonacci\n");
        printf("Enter 4 for Power of a and b\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {

        case 1:
            printf("\n*******************************\n");
            printf("You are in case 1\n");
            printf("Enter the number whose factorial is to be calculated: ");
            int n;
            scanf("%d", &n);
            printf("The factorial of %d is %d\n", n, factorial(n));
            printf("\n*******************************\n");
            break;
        case 2:
            printf("\n*******************************\n");
            printf("You are in case 2\n");
            printf("Enter the nth term of Natural Series: ");
            int m;
            scanf("%d", &m);
            printf("The sum of series is %d\n", SumN(m));
            printf("\n*******************************\n");
            break;
        case 3:
            printf("\n*******************************\n");
            printf("You are in case 3\n");
            fibonacci();
            printf("\n");
            printf("\n*******************************\n");
            break;
        case 4:
            printf("\n*******************************\n");
            printf("You are in case 4\n");
            int a, b;
            printf("Enter the value of a and b: ");
            scanf("%d %d", &a, &b);

            printf("The value of %d to the power %d is : %d\n", a, b, power(a, b));
            printf("\n*******************************\n");
            break;
        case 5:
            printf("\n*******************************\n");
            printf("Exiting...\n");
            exit(0);
        default:
            printf("\n*******************************\n");
            printf("Invalid Input\n");
            printf("\n*******************************\n");
        }
    }
    return 0;
}