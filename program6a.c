#include <stdio.h>
#include <stdlib.h>
int size, top = -1;
int *stack;
void push()
{
    if (top >= size - 1)
        printf("Stack Overflow\n");
    else
    {
        printf("Enter Element->");
        int num;
        scanf("%d", &num);
        stack[++top] = num;
    }
}
void pop()
{
    if (top < 0)
        printf("Stack underflow\n");
    else
        printf("Popped element is->%d\n", stack[top--]);
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if (top == size - 1)
    {
        printf("Stack is Full!!\n");
        return 1;
    }
    else
        printf("No!\n");
    return 0;
}
void peek()
{
    if (!isEmpty())
        printf("Top element is -> %d\n", stack[top]);
}
void display()
{
    if (top >= 0)
    {
        printf("Elements are:");
        for (int i = 0; i <= top; i++)
            printf(" %d", stack[i]);
        printf("\n");
    }
    else
        printf("Stack is Empty\n");
}
int main()
{
    int choice;
    printf("Input Max-size->");
    scanf("%d", &size);
    stack = (int *)malloc(size * sizeof(int));
    printf("\n1.Push element\n");
    printf("2.Pop element\n");
    printf("3.Stack is empty?\n");
    printf("4.Stack is full?\n");
    printf("5.Total elements\n");
    printf("6.Peek element\n");
    printf("7.Display elements\n");
    printf("8.Exit\n");
    while (1)
    {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            isFull();
            break;
        case 5:
            printf("Total number of elements->%d\n", top + 1);
            break;
        case 6:
            peek();
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Exiting...");
            exit(0);
            break;
        }
    }

    return 0;
}