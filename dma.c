#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee
{
    int empid;
    char name[20];
    int salary;
};
int count = 0, max;
void add(struct employee *e)
{
    if (count <= max)
    {
        printf("Employee id: ");
        scanf("%d", &(e + count)->empid);
        printf("Employee Name: ");
        scanf("%s", &(e + count)->name);
        printf("Employee Salary: ");
        scanf("%d", &(e + count)->salary);
        count++;
        printf("Employees Added Successfully\n");
    }
    else
    {
        printf("Exceeding Maximum Limit\n");
    }
}
void display(struct employee *e)
{
    if (count == 0)
    {
        printf("No Employee to Display\n");
    }
    else
    {
        printf("Employee Id  |   Name  |  Salary\n\n");
        for (int i = 0; i < count; i++)
        {

            printf("   %d         %s      %d\n", (e + i)->empid, (e + i)->name, (e + i)->salary);
        }
    }
}
void searchbyid(int id,struct employee *e)
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
            if ((e + i)->empid == id)
            {
                f = 1;
                printf("Id: %d\n", (e + i)->empid);
                printf("Name: %s\n", (e + i)->name);
                printf("Salary: %d\n", (e + i)->salary);
            }
        }
        if (f == 0)
        {
            printf("No such employee found\n");
        }
    }
}
void searchbyname(char name[],struct employee *e)
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
            if (strcmp((e + i)->name, name) == 0)
            {
                f = 1;
                printf("Id: %d\n", (e + i)->empid);
                printf("Name: %s\n", (e + i)->name);
                printf("Salary: %d\n", (e + i)->salary);
            }
        }
        if (f == 0)
        {
            printf("No such employee found\n");
        }
    }
}
void highestsalary(struct employee *e)
{
    int maxsalary = 0, id = 0;
    for (int i = 0; i < count; i++)
    {
        if ((e + i)->salary > maxsalary)
        {
            maxsalary = (e + i)->salary;
            id = (e + i)->empid;
        }
    }
    printf("Highest Salary is %d of the Employee having id %d\n", maxsalary, id);
}
int main()
{
    printf("Maximum Number of Employees: ");
    scanf("%d", &max);
    struct employee *e;
    e = (struct employee *)malloc(max * sizeof(struct employee));

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
            add(e);
            break;
        case 2:
            printf("Case 2\n");
            display(e);
            break;
        case 3:
            printf("Case 3\n");
            printf("Enter Employee id to Search: ");
            int id;
            scanf("%d", &id);
            searchbyid(id,e);
            break;
        case 4:
            printf("Case 4\n");
            printf("Enter Employee name to search: ");
            char name[20];
            scanf("%s", name);
            searchbyname(name,e);
            break;
        case 5:
            printf("Case 5\n");
            highestsalary(e);
            break;
        case 6:
            printf("Exiting\n");
            exit(0);
        }
    }

    return 0;
}