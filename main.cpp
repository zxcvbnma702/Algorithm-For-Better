#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

#include <iostream>

typedef struct student
{
    int index;
    char name[20];
    double grade;
    student *next;
} Student;

Student *Build()
{
    Student *head = (Student *)malloc(sizeof(student));
    int n = 6;
    Student *ptr = head;

    while (n--)
    {
        Student *temp = (Student *)malloc(sizeof(student));
        scanf("%d %s %d", &temp->index, &temp->name, &temp->grade);
        ptr->next = temp;
        ptr = temp;
    }
    ptr->next = NULL;
    return head;
}

Student *Build2(FILE *file)
{
    Student *head = (Student *)malloc(sizeof(student));
    Student *p = head;

    if (file)
    {
        // 文件读到末尾返回true
        while (!feof(file))
        {
            Student *temp = (Student *)malloc(sizeof(student));
            fscanf(file, "%d %s %d", &temp->index, &temp->name, &temp->grade);
            p->next = temp;
            p = temp;
        }
        p->next = NULL;
    }
    else
    {
        printf("Error!!");
    }

    return head;
}

void Sort(Student *head)
{
    Student *p = head->next;
    Student *q;

    while (p != nullptr)
    {
        q = p->next;

        while (q != nullptr)
        {
            if (p->grade > q->grade)
            {
                Student tem = *p;
                *p = *q;
                *q = tem;

                tem.next = p->next;
                p->next = q->next;
                q->next = tem.next;
            }
            q = q->next;
        }
        p = p->next;
    }
}

Student *Merge(Student *head1, Student *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    else if (head1->grade < head2->grade)
    {
        head1->next = Merge(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = Merge(head2->next, head1);
        return head2;
    }
}

void print(Student *head)
{
    Student *p = head->next;
    while (p)
    {
        printf("%d %s %d\n", p->index, p->name, p->grade);
        p = p->next;
    }
}

int main()
{
    Student *res = Build();
    FILE *fp = fopen("student.txt", "r");
    Student *res2 = Build2(fp);
    Sort(res);
    Sort(res2);
    print(res);
    printf("\n");
    print(res2);
    printf("\n");
    Student *res3 = Merge(res->next, res2->next);

    print(res3);

    printf("\n");
    return 0;
}
