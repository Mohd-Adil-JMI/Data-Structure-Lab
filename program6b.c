#include <stdio.h>
#include <stdlib.h>

struct arr
{
    int a;
    struct arr *next;
};

struct arr *top = NULL;
int count = -1;

struct arr *push()
{
    struct arr *temp = (struct arr *)malloc(sizeof(struct arr));
    if (temp == NULL)
        printf("Heap Overflow\n");
    else
    {
        printf("Enter Element->");
        scanf("%d", &temp->a);
        temp->next = top;
        top = temp;
        count++;
        return top;
    }
}
void pop()
{
    struct arr *temp;
    if (top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        temp = top;
        top = top->next;
        temp->next = NULL;
        printf("Popped element->%d\n",temp->a);
        free(temp);
        count--;
    }
}
void display()
{
    struct arr* temp;
    if (count == -1)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        temp=top;
        printf("Elements are:");
        while (temp != NULL)
        {
            printf(" %d", (temp)->a);
            temp = temp->next;
        }
        printf("\n");
    }
}
int isEmpty()
{
    return top == NULL;
}
int peek()
{
    if (!isEmpty())
        return top->a;
}
int main()
{
    int choice;
    printf("\n1.Push element\n");
    printf("2.Pop element\n");
    printf("3.IsEmpty?\n");
    printf("4.Top or Peek element\n");
    printf("5.Total elements\n");
    printf("6.Display elements\n");
    printf("7.Exit\n");
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
            printf("%d\n", isEmpty());
            break;
        case 4:
            printf("Top element is -> %d\n",peek());
            break;
        case 5:
            printf("Total number of elements->%d\n", count + 1);
            break;
        case 6:
            display();
            break;
        case 7:
            printf("Exiting...");
            exit(0);
            break;
        }
    }

    return 0;
}