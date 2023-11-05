#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

#include <iostream>

typedef struct ListNode
{
    int val;
    ListNode *next;
} Lis;

// 利用双指针进行逆置
Lis *Reverse(Lis *head)
{
    Lis *pre = nullptr;
    Lis *cur = head;
    Lis *temp;

    while (cur != nullptr)
    {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }

    return pre;
}

Lis *Merge(Lis *head1, Lis *head2)
{
    Lis *p = Reverse(head1);
    Lis *q = Reverse(head2);

    Lis *head, *rear;

    if (p == nullptr)
    {
        return q;
    }
    else if (q == nullptr)
    {
        return p;
    }

    if (p->val > q->val)
    {
        head = p;
        p = p->next;
    }
    else
    {
        head = q;
        q = q->next;
    }

    rear = head;

    while (q != nullptr && p != nullptr)
    {
        if (p->val > q->val)
        {
            rear->next = p;
            p = p->next;
        }
        else
        {
            rear->next = q;
            q = q->next;
        }
        rear = rear->next;
    }

    if(p != nullptr)
    {
        rear->next = p;
    }

    if(q != nullptr)
    {
        rear ->next = q;
    }

    return head;
}
