#include <stdio.h>

int Queue[5];
int Queue1[5];
int Queue2[5];
int f1, r1, f2, r2, f3, r3 = -1;

void enqueue(int x)
{
    if (r1 == 4)
    {
        if (r2 == 4)
        {
            if (r3 == 4)
                printf("Queue is full!\n");
            else
                Queue2[++r3] = x;
        }
        else
            Queue1[++r2] = x;
    }
    else
        Queue[++r1] = x;
}
int dequeue()
{
    if (f1 == r1)
    {
        if (f2 == r2)
        {
            if (f3 == r3)
                printf("Queue is Empty!\n");
            else
            {
                int temp = Queue2[++f3];
                return temp;
            }
        }
        else
        {
            int temp = Queue1[++f2];
            return temp;
        }
    }
    else
    {
        int temp = Queue[++f1];
        return temp;
    }
}
int main(){
    
    return 0;
}