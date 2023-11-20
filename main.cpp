#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

#include <iostream>

typedef struct TreeNode
{
    int val;
    TreeNode *left, *right;
} TreeNode;

int IsBanlanceTree(TreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
        return 0;

    int left = IsBanlanceTree(root->left);
    int right = IsBanlanceTree(root->right);

    if (left == -1 || right == -1)
    {
        return -1;
    }

    if (abs(left - right) > 1)
    {
        return -1;
    }

    return max(left, right) + 1;
}