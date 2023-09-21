#pragma once
#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 前序遍历
class Solution
{
public:
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == nullptr)
            return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        traversal(root, vec);
        return vec;
    }
};
// 中序遍历
class Solution
{
public:
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == nullptr)
            return;
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        traversal(root, vec);
        return vec;
    }
};
// 后序遍历
class Solution
{
public:
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == nullptr)
            return;
        traversal(cur->left, vec);
        traversal(cur->right, vec);
        vec.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        traversal(root, vec);
        return vec;
    }
};
// 前序非递归遍历
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> vec;
        if (root == nullptr)
            return vec;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *temp = st.top();
            st.pop();
            vec.push_back(temp->val);
            // 前序，需要以中右左的顺序添加入栈
            if (temp->right != nullptr)
                st.push(temp->right);
            if (temp->left != nullptr)
                st.push(temp->left);
        }
        return vec;
    }
};
// 后序非递归遍历
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> vec;
        if (root == nullptr)
            return vec;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *temp = st.top();
            st.pop();
            vec.push_back(temp->val);
            // 后序，需要以中左右的顺序添加入栈
            if (temp->left != nullptr)
                st.push(temp->left);
            if (temp->right != nullptr)
                st.push(temp->right);
        }
        // 最后将存储的中右左顺序翻转为左右中
        reverse(vec.begin(), vec.end());
        return vec;
    }
};
// 中序非递归遍历
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        // 中序非递归需要一个指针,首先指向根节点
        TreeNode *cur = root;

        while (cur != nullptr || !st.empty())
        {
            if (cur != nullptr) // 指针向左访问到底
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                result.push_back(cur->val); // 中
                cur = cur->right;
            }
        }
        return result;
    }
};

// 层序遍历
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> que;
        if (root != nullptr)
            que.push(root);
        vector<vector<int>> result;
        while (!que.empty())
        {
            int size = que.size(); // 记录每层节点数目
            vector<int> vec;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};

// N叉树的遍历
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        queue<Node *> que;
        vector<vector<int>> result;
        if (root != nullptr)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++)
            {
                Node *node = que.front();
                que.pop();
                vec.push_back(node->val);
                // 将所有子节点加入队列
                for (Node *p : node->children)
                {
                    que.push(p);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};

// 填充下一个右侧节点
class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> que;
        if (root != NULL)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            // vector<int> vec;
            Node *nodePre;
            Node *node;
            for (int i = 0; i < size; i++)
            {
                if (i == 0)
                {
                    nodePre = que.front(); // 取出一层的头结点
                    que.pop();
                    node = nodePre;
                }
                else
                {
                    node = que.front();
                    que.pop();
                    nodePre->next = node; // 本层前一个节点next指向本节点
                    nodePre = nodePre->next;
                }
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            nodePre->next = NULL; // 本层最后一个节点指向NULL
        }
        return root;
    }
};

// 翻转二叉树
class Solution
{
public:
    void swapT(TreeNode *root)
    {
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        swapT(root);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// 后序翻转二叉树
class Solution
{
public:
    void swapT(TreeNode *root)
    {
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        invertTree(root->left);
        invertTree(root->right);
        swapT(root);
        return root;
    }
};

// 中序翻转二叉树
class Solution
{
public:
    void swapT(TreeNode *root)
    {
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        invertTree(root->left); // 中序->左中右
        swapT(root);            // 未处理的右子树被翻转到了左边
        invertTree(root->left); // 所以继续处理左子树
        return root;
    }
};

// 层序翻转二叉树
class Solution
{
public:
    void swapT(TreeNode *root)
    {
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    TreeNode *invertTree(TreeNode *root)
    {
        queue<TreeNode *> que;
        if (root == nullptr)
        {
            return nullptr;
        }
        else
        {
            que.push(root);
        };

        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                swapT(node);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return root;
    }
};