#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Shop
{
    char name[20];
    double price;
    int num;
    double totalprice;
    Shop *next;
} Shop;

Shop *create(FILE *fp)
{
    Shop *head = (Shop *)malloc(sizeof(Shop));
    Shop *tail = head;

    while (1)
    {
        Shop *temp = (Shop *)malloc(sizeof(Shop));
        fscanf(fp, "%s %lf %d %lf", &temp->name, &temp->price, &temp->num, &temp->totalprice);
        tail->next = temp;
        tail = temp;
        if (feof(fp))
            break;
    }
    tail->next = NULL;
    return head;
}

int main()
{
    FILE *fp1 = fopen("file1.txt", "r");
    FILE *fp2 = fopen("file2.txt", "r");

    Shop *shop1 = create(fp1);
    Shop *shop2 = create(fp2);

    double total1, total2;

    printf("first people\n");
    Shop *first = shop1->next;
    while (first)
    {
        total1 += first->totalprice;
        printf("%s -> ", first->name);

        first = first->next;
    }
    printf("\nfirst: %lf\n", total1);

    printf("second people\n");
    for (Shop *it = shop2->next; it != nullptr; it = it->next)
    {
        total2 += it->totalprice;
        printf("%s -> ", it->name);
    }
    printf("\nsecond: %lf\n", total2);

    printf("插值: %lf", abs(total1 - total2));

    return 0;
}
