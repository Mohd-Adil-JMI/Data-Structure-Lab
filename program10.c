#include <stdio.h>
#include <stdlib.h>

struct PQueue
{
    char n[4];
    int pr;
    struct PQueue *next;
} *front = NULL, *rear = NULL;

int count = 0;

void enqueue()
{
    struct PQueue *temp = malloc(sizeof(struct PQueue));
    if (temp == NULL)
        printf("Heap Overflow\n");
    else
    {
        printf("Enter the String : ");
        scanf("%s",temp->n);
        printf("Priority : ");
        scanf("%d",&temp->pr);
        temp->next = NULL;
        if (front == NULL || temp->pr < front->pr)
        {
            temp->next = front;
            front = temp;
        }
        else
        {
            struct PQueue *p = front;
            while (p->next != NULL && p->next->pr < temp->pr)
                p = p->next;
            temp->next = p->next;
            p->next = temp;
        }
        count++;
    }
}
void dequeue()
{
    if (front == NULL)
        printf("Queue Underflow\n");
    else
    {
        struct PQueue *temp = front;
        front = front->next;
        printf("Deleted Element : %s\n",temp->n);
        free(temp);
        count--;
    }
}
void Display()
{
    if (front == NULL)
        printf("Queue is Empty\n");
    else
    {
        struct PQueue *temp = front;
        printf("String\tPriority\n");
        while (temp != NULL)
        {
            printf("%s\t%d\n",temp->n,temp->pr);
            temp = temp->next;
        }
    }
}
int isEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}
int main()
{
    int choice;
    printf("\n1. Enqueue\n2. Dequeue\n3. Front and Rear Element \n4. Isempty\n5. Total no of element\n6. Display\n7. Exit\n");
    while (1)
    {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            enqueue();
            Display();
            break;
        case 2:
            dequeue();
            Display();
            break;
        case 3:
            printf("Front Element -> %s\n",front->n);
            struct PQueue *temp = front;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            rear = temp;
            printf("Rear Element -> %s\n",rear->n);
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