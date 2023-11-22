#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

#include <iostream>

typedef struct DLinkNode
{
    DLinkNode *LLink;
    DLinkNode *RLink;
    int Data;
    int Freq;
} DLinkNode;

void Locate(DLinkNode l, int x)
{
    DLinkNode *p = l->RLink;
    while (p != NULL && p->Data != x)
    {
        p = p->RLink;
    }
    if (p != NULL)
    {
        p - > Freq++;
    }

    DLinkNode *q = p;
    while (q ! = l && q->Freq < p->Freq)
    {
        q = q->LLink;
    }
    if (q != l)
    {
        p->LLink->RLink = p->RLink;
        p->RLink->LLink = p->LLink;

        p->LLink = q;
        p->RLink = q->RLink;
        q->RLink = p;
        p->RLink->LLink = p;
    }
}
