#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

#include <iostream>

typedef struct LinkNode
{
    int data;
    LinkNode *next;
} LinkNode;

bool IsPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
                return false;
        }
    }

    return true;
}

LinkNode *deleteSu(LinkNode *head)
{
    LinkNode *dummyHead = (LinkNode *)malloc(sizeof(LinkNode));
    dummyHead->next = head;
    LinkNode *pre = dummyHead;
    LinkNode *cur = head;

    while (cur != NULL)
    {
        if (IsPrime(cur->data))
        {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
    return dummyHead->next;
}

LinkNode *merge(LinkNode *a, LinkNode *b)
{
    LinkNode *dummyHead = (LinkNode *)malloc(sizeof(LinkNode));
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    LinkNode *left = a, *right = b;
    LinkNode *cur = dummyHead;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            cur->next = left;
            left = left->next;
        }
        else
        {
            cur->next = right;
            right = righ->next;
        }
        cur = cur->next;
    }
    if (left != NULL)
    {
        cur->next = left;
    }
    if (right != NULL)
    {
        cur->next = right;
    }
    return dummyHead->next;
}

LinkNode *merSort(LinkNode *head)
{
    LinkNode *slow = head, *fast = head, *midBefore;

    while (fast->next != NULL)
    {
        midBefore = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    midBefore->next = NULL;

    LinkNode *left = merge(head);
    LinkNode *right = merge(slow);
    return merge(left, right);
}

LinkNode *jieguo(LinkNode *head)
{
    LinkNode *res = merSort(head);
    res = deleteSu(res);
    return res;
}