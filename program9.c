#include <stdio.h>
#include <stdlib.h>

struct QueueNode
{
    int data;
    struct QueueNode *QueueNext;
} *front = NULL, *rear = NULL;

int count=0;
void enqueue()
{
    struct QueueNode *temp = malloc(sizeof(struct QueueNode));
    if (temp == NULL)
        printf("Heap Overflow\n");
    else
    {
        printf("Enter the Number : ");
        int x;
        scanf("%d", &x);
        temp->data = x;
        temp->QueueNext = NULL;
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->QueueNext = temp;
            rear = temp;
        }
        count++;
    }
}
int dequeue()
{
    int x = -1;
    struct QueueNode *temp;
    if (front == NULL)
    {
        printf("Queue is Empty \n");
    }
    else
    {
        x = front->data;
        temp = front;
        front = front->QueueNext;
        free(temp);
        count--;
        return x;
    }
}
int isEmpty()
{
    if (front == NULL)
        return 1;
    return 0;
}
void Display()
{
    struct QueueNode *temp;
    temp = front;
    printf("Queue -> ");
    while (temp)
    {
        printf("%d | ", temp->data);
        temp = temp->QueueNext;
    }
    printf("\n");
}
int main()
{
    int choice;
    printf("\n1. Enqueue\n2. Dequeue\n3. Front and Rear Element \n4. Isempty\n5. Total no of element\n6. Display\n7. Exit\n");
    while (1)
    {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            Display();
            break;
        case 2:
            printf("Dequeued element -> %d\n", dequeue());
            Display();
            break;
        case 3:
            printf("Front Element -> %d\n", front->data);
            printf("Rear Element -> %d\n", rear->data);
            break;
        case 4:
            printf("%d\n", isEmpty());
            break;
        case 5:
            printf("Total number of elements -> %d\n", count);
            break;
        case 6:
            Display();
            break;
        case 7:
            printf("Exiting...");
            exit(0);
            break;
        }
    }

    return 0;
}