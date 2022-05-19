#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}
void enqueue(struct Queue *q)
{
    if (q->rear == q->size - 1)
        printf("Queue is Full\n");
    else
    {
        printf("Enter Element : ");
        int n;
        scanf("%d", &n);
        q->rear++;
        q->Q[q->rear] = n;
    }
}
int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {

        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue *q)
{
    if (q->front == q->rear)
        printf("Queue is Empty\n");
    return 1;
    return 0;
}
int isFull(struct Queue *q)
{
    if (q->rear >= q->size - 1)
        printf("Queue is full!\n");
    return 1;
    return 0;
}
void Display(struct Queue q)
{
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}
int main()
{
    struct Queue q;
    create(&q, 5);
    int choice;
    printf("\n1. Enqueue\n2. Dequeue\n3. Front and Rear Element \n4. Isempty\n5. Isfull\n6. Total no of element\n7. Display\n8. Exit\n");
    while (1)
    {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            printf("Dequeued element->%d\n", dequeue(&q));
            break;
        case 3:
            printf("Front Element->%d\n", q.Q[q.front + 1]);
            printf("Rear Element->%d\n", q.Q[q.rear]);
        case 4:
            isEmpty(&q);
            break;
        case 5:
            isFull(&q);
            break;
        case 6:
            printf("Total number of elements->%d\n", q.rear - q.front);
            break;
        case 7:
            Display(q);
            break;
        case 8:
            printf("Exiting...");
            exit(0);
            break;
        }
    }

    return 0;
}