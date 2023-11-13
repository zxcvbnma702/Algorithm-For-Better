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

void preorder(struct TreeNode *root, int *res, int *resSize)
{
    if (root == NULL)
        return;

    res[(*resSize)++] = root->val;
    preorder(root->left, res, resSize);
    preorder(root->right, res, resSize);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *res = malloc(sizeof(int) * 2000);
    *returnSize = 0;
    preorder(root, res, returnSize);
    return res;
}

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

void inorder(struct TreeNode *root, int *res, int *returnSize)
{
    if (root == NULL)
        return;
    inorder(root->left, res, returnSize);
    res[(*returnSize)++] = root->val;
    inorder(root->right, res, returnSize);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *res = malloc(sizeof(int) * 2000);
    *returnSize = 0;
    inorder(root, res, returnSize);
    return res;
}
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

void postorder(struct TreeNode *root, int *res, int *returnSize)
{
    if (root == NULL)
        return;
    postorder(root->left, res, returnSize);

    postorder(root->right, res, returnSize);
    res[(*returnSize)++] = root->val;
}

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *res = malloc(sizeof(int) * 2000);
    *returnSize = 0;
    postorder(root, res, returnSize);
    return res;
}
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

// 平衡二叉树
class Solution
{
public:
    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int leftHeight = getHeight(root->left);
        if (leftHeight == -1)
            return -1;

        int rightHeight = getHeight(root->right);
        if (rightHeight == -1)
            return -1;

        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode *root)
    {
        return getHeight(root) != -1;
    }
};

// 根节点的所有路径
class Solution
{
public:
    // 所有路径，从根节点开始
    // 前序遍历
    void backTracing(TreeNode *node, vector<int> &path, vector<string> &result)
    {

        path.push_back(node->val); // 写在终止条件前，否则叶子结点会被跳过去

        if (node->left == nullptr && node->right == nullptr)
        {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++)
            {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }

        // 必要判空，递归进去没收到值，出来弹值，少一个节点
        // 假设到了左叶子结点，存完路径，然后存右叶子结点
        // 此时path中就需要删除掉左叶子结点再存右叶子结点
        // 这就是一个回溯的过程
        if (node->left)
        {
            backTracing(node->left, path, result);
            path.pop_back();
        }

        if (node->right)
        {
            backTracing(node->right, path, result);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        vector<int> path;
        if (root == nullptr)
            return result;
        backTracing(root, path, result);
        return result;
    }
};

// 路径总和
class Solution
{
public:
    bool result = false;
    void backTracing(TreeNode *node, int targetSum)
    {
        targetSum -= node->val;

        if (node->left == nullptr && node->right == nullptr)
        {
            if (0 == targetSum)
            {
                result = true;
            }
            return;
        }

        if (node->left != nullptr)
        {
            // 注意不需要targetSum += val，因为我们是在进入递归之后才进行值的加减，如果加，就把上面刚加的值减下去了
            backTracing(node->left, targetSum);
        }

        if (node->right != nullptr)
        {
            backTracing(node->right, targetSum);
        }
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;

        backTracing(root, targetSum);
        return result;
    }
};

// 路径总和2
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;

    void backTracing(TreeNode *node, int targetSum, int sum)
    {
        path.push_back(node->val);
        sum += node->val;

        if (node->left == nullptr && node->right == nullptr)
        {
            if (sum == targetSum)
            {
                result.push_back(path);
            }
            return;
        }

        if (node->left != nullptr)
        {
            // 注意不需要sum -= val，因为我们是在进入递归之后才进行值的加减，如果减，就把上面刚加的值减下去了
            backTracing(node->left, targetSum, sum);
            path.pop_back();
            // 因为每次递归都只在开头执行一次path.push_back()，即每次递归path中都只会加入一个结点值，因此执行完一次递归(push一次)再pop一次就能回到之前的path
        }

        if (node->right != nullptr)
        {
            backTracing(node->right, targetSum, sum);
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return result;

        backTracing(root, targetSum, 0);
        return result;
    }
};

// 路径总合2-回溯
class solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    // 递归函数不需要返回值，因为我们要遍历整个树
    void traversal(TreeNode *cur, int count)
    {
        if (!cur->left && !cur->right && count == 0)
        { // 遇到了叶子节点且找到了和为sum的路径
            result.push_back(path);
            return;
        }

        if (!cur->left && !cur->right)
            return; // 遇到叶子节点而没有找到合适的边，直接返回

        if (cur->left)
        { // 左 （空节点不遍历）
            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count); // 递归
            count += cur->left->val;     // 回溯
            path.pop_back();             // 回溯
        }

        if (cur->right)
        { // 右 （空节点不遍历）
            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count); // 递归
            count += cur->right->val;     // 回溯
            path.pop_back();              // 回溯
        }
        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        result.clear();
        path.clear();
        if (root == NULL)
            return result;
        path.push_back(root->val); // 把根节点放进路径
        traversal(root, sum - root->val);
        return result;
    }
};

// 从中序和后序构造二叉树
class Solution
{
public:
    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder)
    {
        // 1. 如果数组为空，空树
        if (postorder.size() == 0)
            return nullptr;

        // 2. 后序遍历最后一个元素，就是中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootValue);

        // 叶子结点直接返回
        if (postorder.size() == 1)
            return root;

        // 3. 找到中序遍历切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
        {
            if (inorder[delimiterIndex] == rootValue)
                break;
        }

        // 4. 切割中序数组
        // 左闭右开区间：[0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        // [delimiterIndex + 1, end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        // postorder 舍弃末尾元素
        postorder.resize(postorder.size() - 1);

        // 5. 切割后序数组
        // 依然左闭右开，注意这里使用了左中序数组大小作为切割点
        // [0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        // 6. 递归处理左右区间
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        return traversal(inorder, postorder);
    }
}

// 从前序和中序构造二叉树
class Solution
{
public:
    TreeNode *traversal(vector<int> &preorder, int preorderBegin, int preorderEnd, vector<int> &inorder, int inorderBegin, int inorderEnd)
    {
        // 1. 判断是否为空树
        if (preorderBegin == preorderEnd)
            return nullptr;

        // 2. 获取中结点
        int nodeValue = preorder[preorderBegin];
        TreeNode *root = new TreeNode(nodeValue);

        // 如果为叶子结点，直接返回
        if (preorderEnd - preorderBegin == 1)
            return root;

        // 3. 寻找切割点
        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++)
        {
            if (inorder[delimiterIndex] == nodeValue)
                break;
        }

        // 4. 切割中序数组
        // 左中序区间，左闭右开[leftInorderBegin, leftInorderEnd)
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;

        // 右中序区间，左闭右开[rightInorderBegin, rightInorderEnd)
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        // 5. 切割前序数组
        // 左子树的前序数组，去除根节点
        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd = preorderBegin + leftInorderEnd - leftInorderBegin + 1; // 不加一会漏掉一个

        // 右子树的前序数，
        int rightPreorderBegin = preorderBegin + (leftInorderEnd - leftInorderBegin) + 1;
        int rightPreorderEnd = preorderEnd;

        // 6. 递归左右子树
        root->left = traversal(preorder, leftPreorderBegin, leftPreorderEnd, inorder, leftInorderBegin, leftInorderEnd);
        root->right = traversal(preorder, rightPreorderBegin, rightPreorderEnd, inorder, rightInorderBegin, rightInorderEnd);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0 || inorder.size() == 0)
            return nullptr;

        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};

// 最大二叉树
class Solution
{
public:
    TreeNode *traverse(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return nullptr;

        // 获取最大值
        int deli = left;
        for (int i = left; i < right; i++)
        {
            if (nums[i] > nums[deli])
                deli = i;
        }

        TreeNode *root = new TreeNode(nums[deli]);

        if (nums.size() == 1)
            return root;

        // 重点切割数组
        root->left = traverse(nums, left, deli);
        root->right = traverse(nums, deli + 1, right);

        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return traverse(nums, 0, nums.size());
    }
};

// 合并二叉树
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        root1->val = root1->val + root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};

// 二叉搜索树中的搜索-递归法
class Solution
{
public:
    TreeNode *result;

    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val == val)
            result = root;
        else if (root->val < val)
            searchBST(root->right, val);
        else
            searchBST(root->left, val);

        return result;
    }
};

// 二叉搜索树中的搜索-迭代法
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root != NULL)
        {
            if (root->val > val)
                root = root->left;
            else if (root->val < val)
                root = root->right;
            else
                return root;
        }
        return NULL;
    }
};

// 验证二叉搜索树-使用数组
class Solution
{
private:
    vector<int> vec;
    void traversal(TreeNode *root)
    {
        if (root == NULL)
            return;
        traversal(root->left);
        vec.push_back(root->val); // 将二叉搜索树转换为有序数组
        traversal(root->right);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        vec.clear(); // 不加这句在leetcode上也可以过，但最好加上
        traversal(root);
        for (int i = 1; i < vec.size(); i++)
        {
            // 注意要小于等于，搜索树里不能有相同元素
            if (vec[i] <= vec[i - 1])
                return false;
        }
        return true;
    }
};

// 验证二叉搜索树-双指针
class Solution
{
public:
    TreeNode *pre = nullptr;
    bool isValidBST(TreeNode *root)
    {

        if (root == nullptr)
            return true;

        bool left = isValidBST(root->left);

        if (pre != nullptr && pre->val >= root->val)
            return false;
        pre = root;

        bool right = isValidBST(root->right);

        return left && right;
    }
};

// 二叉树的最小绝对差-双指针
class Solution
{
public:
    TreeNode *pre = nullptr;
    int minSub = INT_MAX;

    void getMinSub(TreeNode *root)
    {
        if (root == nullptr)
            return;

        getMinimumDifference(root->left);

        if (pre != nullptr)
        {
            minSub = min(root->val - pre->val, minSub);
        }

        pre = root;

        getMinimumDifference(root->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        getMinSub(root);
        return minSub;
    }
};

// 二叉树的最小绝对差-数组
class Solution
{
private:
    vector<int> vec;
    void traversal(TreeNode *root)
    {
        if (root == NULL)
            return;
        traversal(root->left);
        vec.push_back(root->val); // 将二叉搜索树转换为有序数组
        traversal(root->right);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        vec.clear();
        traversal(root);
        if (vec.size() < 2)
            return 0;
        int result = INT_MAX;
        for (int i = 1; i < vec.size(); i++)
        { // 统计有序数组的最小差值
            result = min(result, vec[i] - vec[i - 1]);
        }
        return result;
    }
};

// 二叉搜索树中的众数
class Solution
{
private:
    int maxCount = 0; // 最大频率
    int count = 0;    // 统计频率
    TreeNode *pre = NULL;
    vector<int> result;
    void searchBST(TreeNode *cur)
    {
        if (cur == NULL)
            return;

        searchBST(cur->left); // 左
                              // 中
        if (pre == NULL)
        { // 第一个节点
            count = 1;
        }
        else if (pre->val == cur->val)
        { // 与前一个节点数值相同
            count++;
        }
        else
        { // 与前一个节点数值不同
            count = 1;
        }
        pre = cur; // 更新上一个节点

        if (count == maxCount)
        { // 如果和最大值相同，放进result中
            result.push_back(cur->val);
        }

        if (count > maxCount)
        {                     // 如果计数大于最大值频率
            maxCount = count; // 更新最大频率
            result.clear();   // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
            result.push_back(cur->val);
        }

        searchBST(cur->right); // 右
        return;
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        count = 0;
        maxCount = 0;
        pre = NULL; // 记录前一个节点
        result.clear();

        searchBST(root);
        return result;
    }
};

// 二叉树的最近公共祖先
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
            return root;

        // 你得先知道子节点有没有pq之后才能判断自己是不是祖先
        // 所以后序遍历左右中最为合适
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr)
            return root;
        if (left != nullptr && right == nullptr)
            return left;
        if (left == nullptr && right != nullptr)
            return right;
        if (left == nullptr && right == nullptr)
            return nullptr;

        return nullptr;
    }
};

// 二叉搜索树的最近公共祖先-递归法
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;

        if (root->val < p->val && root->val < q->val)
        {
            TreeNode *right = lowestCommonAncestor(root->right, p, q);
            if (right != NULL)
                return right;
        }
        else if (root->val > p->val && root->val > q->val)
        {
            TreeNode *left = lowestCommonAncestor(root->left, p, q);
            if (left != NULL)
                return left;
        }
        else
        {
            return root;
        }

        return NULL;
    }
};

// 二叉搜索树的最近公共祖先-迭代法
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root != NULL)
        {
            if (root->val > p->val && root->val > q->val)
            {
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return NULL;
    }
};

// 二叉搜索树的插入操作
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {

        if (root == nullptr)
            root = new TreeNode(val);

        if (root->val < val)
        {
            if (root->right)
            {
                insertIntoBST(root->right, val);
            }
            else
            {
                root->right = new TreeNode(val);
            }
        }
        else if (root->val > val)
        {
            if (root->left)
            {
                insertIntoBST(root->left, val);
            }
            else
            {
                root->left = new TreeNode(val);
            }
        }

        return root;
    }
};

// 二叉搜索树的删除操作
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val == key) // 找到了要删除的节点
        {
            // 如果要删除的点是叶子结点，直接删
            if (root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }
            else if (root->left == nullptr && root->right != nullptr)
            {
                return root->right;
            }
            else if (root->right == nullptr && root->left != nullptr)
            {
                return root->left;
            }
            else
            {
                TreeNode *cur = root->right;
                // 注意: cur!=null 到最后指针就指向空了，就没意义了
                while (cur->left != nullptr)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                return root->right;
            }
        }

        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};

// 修剪二叉搜索树
class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return nullptr;

        // 比最小值还小,修剪右子树
        if (root->val < low)
        {
            TreeNode *right = trimBST(root->right, low, high);
            return right;
        }

        if (root->val > high)
        {
            TreeNode *left = trimBST(root->left, low, high);
            return left;
        }

        root->left = trimBST(root->left, low, high);   // root->left接入符合条件的左孩子
        root->right = trimBST(root->right, low, high); // root->right接入符合条件的右孩子
        return root;
    }
};
// 将有序数组转换为二叉搜索树
class Solution
{
private:
    TreeNode *traversal(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = left + ((right - left) / 2);
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root = traversal(nums, 0, nums.size() - 1);
        return root;
    }
};

// 将有序数组转换为二叉搜索树
class Solution
{
public:
    TreeNode *pre = nullptr;
    TreeNode *convertBST(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        convertBST(root->right);

        if (pre != nullptr)
        {
            root->val = pre->val + root->val;
        }

        pre = root;

        convertBST(root->left);

        return root;
    }
};