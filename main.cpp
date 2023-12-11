#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

#include <iostream>

#define maxnum 1000

typedef struct EdgeNode
{
    int data;
    int edgeLen;
    EdgeNode *next;
} EdgeNode;

typedef struct ArcNode
{
    int data;
    EdgeNode *first;
} ArcNode;

typedef struct AGraph
{
    int nodeNum;
    int edgeNUm;
    ArcNode adjlist[maxnum];
} AGraph;

typedef struct TreeNode
{
    int data, childNum;
    TreeNode *children[maxnum];
} TreeNode;

TreeNode *bfs(AGraph *g, int v)
{
    TreeNode **queue = (TreeNode **)malloc(sizeof(TreeNode *) * g->nodeNum);

    int rear = -1, front = -1;

    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->data = k;

    queue[++rear] = root;

    int visited[g->nodeNum] = {0};

    visited[v] = 1;

    while (front != rear)
    {
        TreeNode *p = queue[++front];

        p->childNum = 0;

        EdgeNode *q = g->adjlist[p->data].first;

        while (q != NULL)
        {
            if (visited[q->data] != 1)
            {
                TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
                temp->data = q->data;

                p->children[p->childNum++] = temp;
                queue[++rear] = temp;
                visited[q->data] = 1;
            }
            q = q->next;
        }
    }

    return root;
}
