#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct employee
{
    int empid;
    char name[20];
    int salary;
};
struct employee e[10];
int count = 0;
void add(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Employee id: ");
        scanf("%d", &e[i].empid);
        printf("Employee Name: ");
        scanf("%s", &e[i].name);
        printf("Employee Salary: ");
        scanf("%d", &e[i].salary);
        count++;
    }
    printf("Employees Added Successfully\n");
}
void display()
{
    if (count == 0)
    {
        printf("No Employee to Display\n");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            printf("Employee No. %d\n", i + 1);
            printf("Id: %d\n", e[i].empid);
            printf("Name: %s\n", e[i].name);
            printf("Salary: %d\n", e[i].salary);
        }
    }
}
void searchbyid(int id)
{
    if (count == 0)
    {
        printf("No Employee to Search\n");
    }
    else
    {
        int f = 0;
        for (int i = 0; i < count; i++)
        {
            if (e[i].empid == id)
            {
                f = 1;
                printf("Id: %d\n", e[i].empid);
                printf("Name: %s\n", e[i].name);
                printf("Salary: %d\n", e[i].salary);
            }
        }
        if (f == 0)
        {
            printf("No such employee found\n");
        }
    }
}
void searchbyname(char name[])
{
    if (count == 0)
    {
        printf("No Employee to Search\n");
    }
    else
    {
        int f = 0;
        for (int i = 0; i < count; i++)
        {
            if (strcmp(e[i].name, name) == 0)
            {
                f = 1;
                printf("Id: %d\n", e[i].empid);
                printf("Name: %s\n", e[i].name);
                printf("Salary: %d\n", e[i].salary);
            }
        }
        if (f == 0)
        {
            printf("No such employee found\n");
        }
    }
}
void highestsalary(){
    int maxsalary=0,id=0;
    for (int i = 0; i < count; i++)
    {
        if (e[i].salary>maxsalary)
        {
            maxsalary=e[i].salary;
            id=e[i].empid;
        }
        
    }
    printf("Highest Salary is %d of the Employee having id %d\n",maxsalary,id);
}
int main()
{

    while (1)
    {
        int ch;
        printf("Enter 1 to Add Employee\n");
        printf("Enter 2 to Display All Employee\n");
        printf("Enter 3 to Search Employee by empid\n");
        printf("Enter 4 to Search Employee by name\n");
        printf("Enter 5 to dispay Employee having highest Salary\n");
        printf("Enetr 6 to Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Case 1\n");
            printf("Enter the number of Employees you want to Add: ");
            int n;
            scanf("%d", &n);
            add(n);
            break;
        case 2:
            printf("Case 2\n");
            display();
            break;
        case 3:
            printf("Case 3\n");
            printf("Enter Employee id to Search: ");
            int id;
            scanf("%d", &id);
            searchbyid(id);
            break;
        case 4:
            printf("Case 4\n");
            printf("Enter Employee name to search: ");
            char name[20];
            scanf("%s", name);
            searchbyname(name);
            break;
        case 5:
            printf("Case 5\n");
            highestsalary();
            break;
        case 6:
            printf("Exiting\n");
            exit(0);
        }
    }

    return 0;
}
