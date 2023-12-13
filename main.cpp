#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

#include <iostream>

#define maxnum 1000

typedef struct TreeNode
{
    int data;
    TreeNode *left, *right;
} TreeNode;

void deleteBinSerTree(TreeNode *root, int k)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == k)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            return left;
        }
        else if (root->right != NULL && root->left == NULL)
        {
            return right;
        }
        else
        {
            TreeNode *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            temp->left = root->left;
            return root->right;
        }
    }

    if (root->data > key)
    {
        deleteBinSerTree(root->left, k);
    }

    if (root->data < key)
    {
        deleteBinSerTree(root->right, k);
    }

    return root;
}
