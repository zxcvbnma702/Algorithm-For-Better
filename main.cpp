#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

#include <iostream>

int odds(int s)
{
}

typedef struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

TreeNode *createByS(int s[], int n)
{
    if (n == 0)
    {
        return NULL;
    }

    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *p = root;
    int i = 0, top = -1;

    TreeNode **stack = (TreeNode **)malloc(sizeof(TreeNode *) * 100);

    while (p != NULL || top != -1)
    {
        if (p != NULL)
        {
            if ([i] == 0)
            {
                p->left = NULL;
                p->right = NULL;
            }
            else if (s[i] == 1)
            {
                TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
                p->left = temp;
                p->right = NULL;
            }
            else if (s[i] == 2)
            {
                TreeNode *temp1 = (TreeNode *)malloc(sizeof(TreeNode));
                TreeNode *temp2 = (TreeNode *)malloc(sizeof(TreeNode));
                p->left = temp1;
                p->right = temp2;
            }

            stack[++top] = p;
            p = p->left;
            i++;
        }
        else
        {
            p = stack[top--];
            p = p->right;
        }
    }

    return root;
}