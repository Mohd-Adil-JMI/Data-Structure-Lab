#include <stdio.h>
#include <stdlib.h>

int A[20];
int Size;

// void print();
// void Insert1();
// void Insert2();
// void Insert3();
// void Delete1();
// void Delete2();
// void Delete3();

// #include <stdio.h>

// int arr[10] = {1, 2, 3};
// int length = 3;
// void display(){
//     for (int i = 0; i < length; i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
// }
// void insertion(int index, int value)
// {
//     for (int i = length; i > index; i--)
//     {
//         arr[i] = arr[i - 1];
//     }
//     arr[index] = value;
//     length++;
// }
// void delete(int index){
//     for (int i = index; i < length; i++)
//     {
//         arr[i]=arr[i+1];
//     }
//    length--; 
// }
// int main()
// {
//     display();
//     insertion(2, 2);
//     display();
//     insertion(0,0);
//     display();
//     insertion(length,8);
//     display();
//     delete(0);
//     display();
//     delete(2);
//     display();
//     return 0;
// }

void print(){
    printf("\nThe array is : ");

    for(int i=0; i<Size; i++){
        printf("%d ", A[i]);
    }
}

void Insert1(){
    if(Size>=20){
        printf("\nSize Overflow!!");
        return;
    }
    
    int v;
    printf("\nEnter the value you want to enter: ");
    scanf("%d", &v);

    for(int i=Size-1; i>=0; i--){
        A[i+1]=A[i];
    }
    A[0] = v;
    Size++;
}

void Insert2(){
    if(Size>=20){
        printf("\nSize Overflow!!");
        return;
    }

    int v;
    printf("\nEnter the value you want to enter: ");
    scanf("%d", &v);

    A[Size] = v;
    Size++;
}

void Insert3(){
    if(Size>=20){
        printf("\nSize Overflow!!");
        return;
    }
    
    int v, pos;
    printf("\nEnter the value you want to enter: ");
    scanf("%d", &v);
    printf("\nEnter the position of this element: ");
    scanf("%d", &pos);

    for(int i=Size-1; i>=pos-1; i--){
        A[i+1]=A[i];
    }
    A[pos-1]= v;
    Size++;
}

void Delete1(){
    if(Size<=0){
        printf("\nSize underflow!!");
        return;
    }
    for(int i=0; i<Size-1; i++){
        A[i] = A[i+1];
    }
    Size--;
}

void Delete2(){
    if(Size<=0){
        printf("\nSize underflow!!");
        return;
    }
    Size--;
}

void Delete3(){
    if(Size<=0){
        printf("\nSize underflow!!");
        return;
    }

    int pos;
    printf("\nEnter the position of this element: ");
    scanf("%d", &pos);
    
    for(int i=pos-1; i<Size-1; i++){
        A[i] = A[i+1];
    }
    Size--;
}


int main(){
    
    printf("\nNumber of elements you want to enter Initially (<20): ");
    scanf("%d", &Size);

    printf("Enter the elements : ");
    for(int i=0; i<Size; i++){
        scanf("%d", &A[i]);
    }
    
    while(1){
        printf("\nPress 1 to add element in beginning");
        printf("\nPress 2 to add element at end");
        printf("\nPress 3 to add element at a certain position");
        printf("\nPress 4 to delete element from begining");
        printf("\nPress 5 to delete element from end");
        printf("\nPress 6 to delete element from any position");
        printf("\nPress 7 to exit the program");
        printf("\nEnter your choice: ");
        int ch;
        scanf("%d", &ch);

        switch(ch){
            case 1 : Insert1();
                     print();
                     break;

            case 2 : Insert2();
                     print();
                     break;

            case 3 : Insert3();
                     print();
                     break;

            case 4 : Delete1();
                     print();
                     break;

            case 5 : Delete2();
                     print();
                     break;

            case 6 :  Delete3();
                     print();
                     break;

            case 7 : printf("\nExiting from the program!");
                     exit(0);

            default : printf("\nWrong choice!");
                      break;
        }
    }
    return 0;
}
