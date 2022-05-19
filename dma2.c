#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee
{
    int empid;
    char name[20];
    int salary;
    struct employee *next;
};
int count = 0;
struct employee *add(struct employee *list)
{
    struct employee *e = (struct employee *)malloc(sizeof(struct employee));
    printf("Employee id: ");
    scanf("%d", &(e)->empid);
    printf("Employee Name: ");
    scanf("%s", &(e)->name);
    printf("Employee Salary: ");
    scanf("%d", &(e)->salary);
    e->next = list;
    list = e;
    count++;
    printf("Employees Added Successfully\n");
    return list;
}
void display(struct employee *list)
{
    if (count == 0)
    {
        printf("No Employee to Display\n");
    }
    else
    {
        printf("ID\tNAME\tSALARY\n");
        while (list != NULL)
        {
            printf("%d\t%s\t%d\n", (list)->empid, (list)->name, (list)->salary);
            list=list->next;
        }
    }
}
void searchbyid(int id, struct employee *list)
{
    while (list != NULL)
        {
            if ((list)->empid == id)
            {
                printf("ID\tNAME\tSALARY\n");
                printf("%d\t%s\t%d\n", (list)->empid, (list)->name, (list)->salary);
            }
            list=list->next;
        }

        if (list==NULL)
        {
            printf("No such employee found\n");
        }
}
void searchbyname(char name[], struct employee *list)
{
    while (list != NULL)
        {
            if (strcmp((list)->name, name) == 0)
            {
                printf("ID\tNAME\tSALARY\n");
                printf("%d\t%s\t%d\n", (list)->empid, (list)->name, (list)->salary);
            }
            list=list->next;
        }

        if (list== NULL)
        {
            printf("No such employee found\n");
        }
}
void highestsalary(struct employee *list)
{
    int maxsalary = 0;
    struct employee *temp = NULL;
    while (list != NULL)
    {
        if (list->salary >= maxsalary)
        {
            maxsalary = list->salary;
            temp = list;
        }
        list = list->next;
    }
    if (temp == NULL)
        printf("Employee not Found\n");
    else
    {
        printf("ID\tNAME\tSALARY\n");
        printf("%d\t%s\t%d\n", (temp)->empid, (temp)->name, (temp)->salary);
    }

    printf("Highest Salary is %d of the Employee having id %d\n", maxsalary, temp->empid);
}
int main()
{
    struct employee *list = NULL;

    printf("Enter 1 to Add Employee\n");
    printf("Enter 2 to Display All Employee\n");
    printf("Enter 3 to Search Employee by empid\n");
    printf("Enter 4 to Search Employee by name\n");
    printf("Enter 5 to dispay Employee having highest Salary\n");
    printf("Enter 6 to display number of Employees\n");
    printf("Enter 7 to Exit\n");
    while (1)
    {
        int ch;
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Case 1\n");
            list = add(list);
            break;
        case 2:
            printf("Case 2\n");
            display(list);
            break;
        case 3:
            printf("Case 3\n");
            printf("Enter Employee id to Search: ");
            int id;
            scanf("%d", &id);
            searchbyid(id, list);
            break;
        case 4:
            printf("Case 4\n");
            printf("Enter Employee name to search: ");
            char name[20];
            scanf("%s", name);
            searchbyname(name, list);
            break;
        case 5:
            printf("Case 5\n");
            highestsalary(list);
            break;
        case 6:
            printf("Case 6\n");
            printf("Total Number of Employees -> %d\n", count);
            break;
        case 7:
            printf("Exiting\n");
            exit(0);
        }
    }

    return 0;
}