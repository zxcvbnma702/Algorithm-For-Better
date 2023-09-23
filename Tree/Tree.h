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
        if (root != nullptr)
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
            nodePre->next = nullptr; // 本层最后一个节点指向nullptr
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

// 对称二叉树-递归遍历
class Solution
{
public:
    bool compare(TreeNode *left, TreeNode *right)
    {
        // 首先排除空节点的情况
        if (left == nullptr && right != nullptr)
            return false;
        else if (left != nullptr && right == nullptr)
            return false;
        else if (left == nullptr && right == nullptr)
            return true;
        // 排除了空节点，再排除数值不相同的情况
        else if (left->val != right->val)
            return false;

        // 此时就是：左右节点都不为空，且数值相同的情况
        // 此时才做递归，做下一层的判断
        bool outside = compare(left->left, right->right); // 左子树：左、 右子树：右
        bool inside = compare(left->right, right->left);  // 左子树：右、 右子树：左
        bool isSame = outside && inside;                  // 左子树：中、 右子树：中 （逻辑处理）
        return isSame;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return compare(root->left, root->right);
    }
};

// 对称二叉树-使用队列
class Solution
{
public:
    // 每次入队以外层内层顺序入队，取出时取两个来比较值是否相等
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        queue<TreeNode *> que;
        que.push(root->left);
        que.push(root->right);

        while (!que.empty())
        {
            TreeNode *left = que.front();
            que.pop();
            TreeNode *right = que.front();
            que.pop();

            if (left == nullptr && right == nullptr)
                continue;

            // 不对称情况
            if (left == nullptr && right != nullptr)
                return false;
            if (left != nullptr && right == nullptr)
                return false;
            if (left->val != right->val)
                return false;

            que.push(right->right);
            que.push(left->left);
            que.push(left->right);
            que.push(right->left);
        }

        return true;
    }
};

// 相同的树
class Solution
{
public:
    bool compare(TreeNode *left, TreeNode *right)
    {
        // 首先排除空节点的情况
        if (left == nullptr && right != nullptr)
            return false;
        else if (left != nullptr && right == nullptr)
            return false;
        else if (left == nullptr && right == nullptr)
            return true;
        // 排除了空节点，再排除数值不相同的情况
        else if (left->val != right->val)
            return false;

        // 此时就是：左右节点都不为空，且数值相同的情况
        // 此时才做递归，做下一层的判断
        bool outside = compare(left->left, right->left);
        bool inside = compare(right->right, left->right);
        bool isSame = outside && inside;
        return isSame;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return compare(p, q);
    }
};

// 二叉树的最大深度-后序遍历
class Solution
{
public:
    int backTracing(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftDepth = backTracing(root->left);
        int rightDepth = backTracing(root->right);

        int maxDepth = max(leftDepth, rightDepth) + 1;
        return maxDepth;
    }

    int maxDepth(TreeNode *root)
    {
        return backTracing(root);
    }
};

// 二叉树的最大深度-前序遍历
class Solution
{
public:
    int result;
    void getDepth(TreeNode *node, int depth)
    {
        result = depth > result ? depth : result; // 中

        if (node->left == NULL && node->right == NULL)
            return;

        if (node->left)
        {            // 左
            depth++; // 深度+1
            getDepth(node->left, depth);
            depth--; // 回溯，深度-1
        }
        if (node->right)
        {            // 右
            depth++; // 深度+1
            getDepth(node->right, depth);
            depth--; // 回溯，深度-1
        }
        return;
    }
    int maxDepth(TreeNode *root)
    {
        result = 0;
        if (root == NULL)
            return result;
        getDepth(root, 1);
        return result;
    }
};

// 二叉树的最小深度-层序遍历
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        queue<TreeNode *> que;
        if (root != nullptr)
            que.push(root);
        int depth = 0;

        while (!que.empty())
        {
            int size = que.size(); // 记录每层节点数目
            depth++;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
                if (!node->left && !node->right)
                    return depth;
            }
        }
        return depth;
    }
};

// 二叉树的最小深度-递归遍历
class Solution
{
public:
    int backTracing(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int leftDepth = backTracing(root->left);
        int rightDepth = backTracing(root->right);

        // 根节点到叶子结点的最短路径
        // 所以单边子树为空的情况不符合最小深度
        if (root->left != nullptr && root->right == nullptr)
            return 1 + leftDepth;
        if (root->right != nullptr && root->left == nullptr)
            return 1 + rightDepth;

        int minDepth = min(leftDepth, rightDepth) + 1;

        return minDepth;
    }

    int minDepth(TreeNode *root)
    {
        return backTracing(root);
    }
};

// 完全二叉树的节点个数-后序遍历
class Solution
{
public:
    int backTracing(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = backTracing(root->left);
        int right = backTracing(root->right);

        int num = left + right + 1;
        return num;
    }

    int countNodes(TreeNode *root)
    {
        return backTracing(root);
    }
};

// 完全二叉树的节点个数-利用满二叉树性质
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftDepth = 0, rightDepth = 0; // 这里初始为0是有目的的，为了下面求指数方便

        while (left)
        { // 求左子树深度
            left = left->left;
            leftDepth++;
        }

        while (right)
        { // 求右子树深度
            right = right->right;
            rightDepth++;
        }

        if (leftDepth == rightDepth) // 此时子树是一颗满二叉树
        {
            return (2 << leftDepth) - 1; // 注意(2<<1) 相当于2^2，所以leftDepth初始为0
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};