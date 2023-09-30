# Algorithm-For-Better

为了考研,努力刷题

## 数组

### 二分搜索

[二分查找](https://leetcode.cn/problems/binary-search/)

> 左闭右闭区间，while(left <= right)，left = middle + 1, right = middle - 1
> 左闭右开区间，while(left < right)，left = middle + 1, right = middle

```c++
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        // 当left==right，区间[left, right]依然有效，所以用 <=
        while (left <= right)
        {
            // 防止溢出 等同于(left + right)/2
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target)
            {
                // target 在左区间，所以[left, middle - 1]
                right = middle - 1;
            }
            else if (nums[middle] < target)
            {
                // target 在右区间，所以[middle + 1, right]
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};
```

[搜索插入的位置](https://leetcode.cn/problems/search-insert-position/description/)

> 直接二分查找返回left即可。
> 根据if的判断条件，left左边的值一直保持小于target，right右边的值一直保持大于等于target，而且left最终一定等于right+1
> 这么一来，循环结束后，在left和right之间画一条竖线，恰好可以把数组分为两部分：left左边的部分和right右边的部分，而且left左边的部分全部小于target，并以right结尾；right右边的部分全部大于等于target，并以left为首。
> 所以最终答案一定在left的位置。

### 移除元素

[移除元素](https://leetcode.cn/problems/remove-element/)

> 双指针法

## 线性表

### 链表的初始化

单链表

```c++
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data = 0;
    Node *next = nullptr;
};

// 初始化链表节点
Node *initList(Node *head, vector<int> a)
{
    Node *cur = head;
    for (int num : a)
    {
        // 给新节点赋值
        Node *newNode = new Node;
        newNode->data = num;
        // 将新节点加入链表
        cur->next = newNode;
        cur = cur->next;
    }
    return head;
}

int main()
{
    Node *head = new Node;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    head = initList(head, a);

    Node* it = head->next;
    while (it != nullptr)
    {
        cout << it->data << " ";
        it = it->next;
    }

    return 0;
}
```

循环链表

```c++
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data = 0;
    Node *next = nullptr;
    Node *prve = nullptr;
};

Node *initList(Node *head, vector<int> a)
{
    Node *cur = head;
    for (int num : a)
    {
        // 给新节点赋值
        Node *newNode = new Node;
        newNode->data = num;
        // 将新节点添加进链表中
        cur->next = newNode;
        newNode->prve = cur;
        cur = cur->next;
    }
    // 将尾结点与头结点连接
    cur->next = head;
    head->prve = cur;

    return head;
}

int main()
{
    Node *head = new Node;
    vector<int> a = {2, 3, 5, 1, 0, 2, 9, 8};
    head = initList(head, a);

    Node *it = head->next;
    while (it != head)
    {
        cout << it->data << " ";
        it = it->next;
    }
    cout << endl;

    it = head->prve;
    while (it != head)
    {
        cout << it->data << " ";
        it = it->prve;
    }
    cout << endl;

    return 0;
}
```

### 递归算法, 删除不带头节点的单链表中所有值为x的点

```c++
Node *deleteNode(int x, Node *cur)
{
    if (cur != nullptr)
    {
        if (cur->data == x)
        {
            // 递归出口
            Node *temp = cur->next;
            delete cur;
            // 如果下一个值是x, 那么就会反复执行, 直到 cur == nullptr 或 到达下面的else分支
            return deleteNode(x, temp);
        }
        else
        {
            // 如果下一个节点为空, 则会返回nullptr
            // 如果下一个节点为x, 则执行上面的if分支得到返回值
            // 如果下一个节点不为x, 那么会不断递归, next连接的节点不变
            cur->next = deleteNode(x, cur->next);
            return cur;
        }
    }
    return nullptr;
}
```

### 链表逆置

迭代写法

```c++
void reserseList(Node *head)
{
    // 判空
    Node *left = head->next;
    if (left == nullptr)
        return;

    // 第二个节点赋值给right
    Node *right = left->next;
    left->next = nullptr;

    /*
    将left暂存起来, 作为转换后的主体链
    将最新的顺序元素赋值给left
    右指针右移
    让最新的顺序元素left接上逆置的主体链
    */
    while (right != nullptr)
    {
        Node *temp = left;
        left = right;
        right = right->next;
        left->next = temp;
    }
    head->next = left;
}
```

## 字符串

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

### 暴力匹配

```c++
// pat 目标串 txt 文本串
int mySearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    // i < 文本串长度 - 目标串长度
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
        {
            if (pat[j] != txt[i + j])
                break;
        }
        // 匹配成功
        if (j == M)
            return i;
    }
    return -1;
}
```

### KMP算法

前缀表特性 一个字符串的最长相等的前后缀

> 前缀是包含首字符不包含尾字母的所有子串
> 后缀是包含尾字符不包含首字母的所有子串
> [理论知识](https://www.bilibili.com/video/BV1PD4y1o7nd/?spm_id_from=333.337.search-card.all.click&vd_source=7e92ec9131757560b71f0a6be9839426) + [代码实现](https://www.bilibili.com/video/BV1M5411j7Xx/?p=22&spm_id_from=pageDriver)

求目标串的最长**相等**的前后缀得到目标串的**前缀表**

```c++
int myKMP(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    /* 初始化 => 前后缀不相同情况 => 前后缀相同的情况 => next数组(前缀表的更新) */

    // 计算next数组, next数组告诉我们当冲突发生时
    // pat串的指针要回退到哪里
    vector<int> next(M);
    next[0] = 0;

    // 起始时, next[0] = 0, j begin with 0, i begin with 1
    // i 指向后缀的末尾位置, i 的作用是遍历目标串, 每次循环确定next[i]的值
    // j 指向前缀的末尾位置, j 还代表了包括 i 之前的最长相等前后缀的长度
    for (int i = 1, j = 0; i < M; i++)
    {
        // 如果 pat[i] != pat[j], 就将 j 指针指向前一位置的 next 数组所对应的值, 即 j = next[j - 1]
        // 这一过程循环进行直到 j == 0 或者 pat[i] == pat[j]
        // 当 pat[i] != pat[j] 时, 不断前移, 去寻找使得前 0 ~ j 个字符为对应的 pat[i]  的尽可能大的相等前后缀
        // 如果 j == 0 了还没找到, 就说明没有和这部分匹配的前后缀
        while (j > 0 && pat[i] != pat[j])
            j = next[j - 1];

        // pat[i] == pat[j], 说明前0 ~ j个字符是最大相等前后缀, 因此最大相等前后缀长度就是j+1
        if (pat[i] == pat[j])
        {
            next[i] = j + 1;
            j++;
        }
        else
        {
            next[i] = 0;
        }
    }

    int i, j = 0;
    // KMP匹配
    while (i < N && j < M)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
                i++;
            else
            {
                // 此时 j 正指向 pat 串中不匹配的字符
                // 所以 pat 串指针回退到的位置要使用 j-1
                j = next[j - 1];
            }
        }
    }

    if (j == M)
        return i - j;
    return -1;
}
```

吉大版
> 与上文主要区别是将整个前缀数组进行了减一操作,
> 所以进行回退操作时需要加一
> 即 `j = fail[j - 1] + 1`

```c++
class Solution {
public:
    int strStr(string S, string T) {
        int n = S.size(), m = T.size();
 
        //以下为计算fail数组过程
        vector<int> fail(m);         //fail数组
        fail[0] = -1;                //起始时，先将fail[0]赋为-1
        //指针j从0开始，指针i从1开始
        //指针i的作用：遍历模式串T，每次循环确定fail[i]的值
        //指针j的作用：当j >= 0，并且T[i] == T[j]时，说明前0 ~ j个字符就是最大相等前后缀，其长度为j + 1
        //当j == 0，且T[i] != T[j]时，就说明无相等前后缀，最大相等前后缀长度为0
        for (int i = 1, j = 0; i < m; i++)
        {
            //如果T[i] != T[j]，就将j指针指向前一位置的fail数组所对应的值，即j = fail[j - 1] + 1
            //这一过程循环进行直到 j == 0 或者 T[i] == T[j]
            //我对这一过程的理解是，当T[i] != T[j]时，一直让j = fail[j - 1] + 1，是为了找到一个j值，
            //使前0 ~ j个字符为对应T[i]的尽可能大的相等前后缀，如果一直到j == 0，T[i]还不等于T[j]，就说明不存在相等前后缀
            while (j > 0 && T[i] != T[j]) j = fail[j - 1] + 1;
            //如果T[i] == T[j]，就令fail[i] = j，指针i和j同时后移
            //T[i] == T[j]，说明前0 ~ j个字符是最大相等前后缀，因此最大相等前后缀长度为j+1，再减一就是j
            if (T[i] == T[j])
            {
                fail[i] = j;
                j++;
            }
            //如果j == 0，且T[i] != T[j]，说明不存在相等前后缀
            else //if (j == 0)
            {
                fail[i] = -1;
            }
        }
 
        //以下为kmp匹配过程
        int i = 0, j = 0;   //i是主串S中的指针，j是模式串T中的指针
        while (i < n && j < m)
        {
            if (S[i] == T[j])
            {
                i++;
                j++;
            }
            else 
            {
                //如果主串S中的S[i]与串T中的第一个字符T[0]就匹配失败，那么主串中的指针i直接移动到下一位
                //将这种特殊情况放在这里写，就不用像王道书上那样，fail数组的第一个元素还得赋一个特值
                //匹配失败时，只有这种情况下需要移动主串中的指针i
                if (j == 0) i++;
                else
                {
                    j = fail[j - 1] + 1;
                }
            }
        }
        //这里可以这么想：如果主串的第一个子串就匹配成功的话，那么最终i和j的值是相等的，于是返回的下标是i - j
        if (j == m) return i - j;
        return -1;
    }
};
```

## 树

> 树转换为二叉树
>
> 1. 在所有的兄弟结点之间加一条线
> 2. 树中的每个结点，只保留它与第一个孩子结点的连线，删除其他孩子结点之间的连线
> 3. 以树的根结点为轴心，将整个树调节一下
>
> ![Alt text](assets/image.png)
>
> 二叉树转换为树
>
> 1. 将二叉树从左上到右下分为若干层。然后调整成水平方向
> 2. 找到每一层节点在其上一层的父节点，加线
> 3. 去除兄弟节点之间的连线
>
> ![Alt text](assets/image-2.png)
>
> 二叉树转换为森林
>
> 前提: 加入一棵二叉树的根节点有右孩子，则这棵二叉树能够转换为森林，否则转换为一棵树。
> ![Alt text](assets/image-3.png)
>
> 1. 从根节点开始，若右孩子存在，则把与右孩子结点的连线删除。再查看分离后的二叉树，若其根节点的右孩子存在，则连续删除。直到所有这些根结点与右孩子的连线都删除为止。
> 2. 将每棵分离后的二叉树转换为树。
> ![Alt text](assets/image-5.png)
>
> 森林转换为二叉树
>
> 1. 第一步每棵树自己先成为一课二叉树
> ![给兄弟加线](assets/image-6.png)
> ![去线](assets/image-7.png)
> ![儿子在左，兄弟在右](assets/image-8.png)
> 2. 从第二棵二叉树开始，每棵二叉树都是上一个二叉树根节点的右孩子
> ![森林转二叉树](assets/image-9.png)

### 二叉树

> 完全二叉树 使用顺序存储 fabulous
> 如果需要搜索**整棵**二叉树，那么递归函数就**不要返回值**，如果要搜索其中**一条**符合条件的路径，递归函数就需要返回值，因为遇到符合条件的路径了就要及时返回。

#### 递归遍历

##### 前序遍历

[前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/description/)

```c++
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
```

##### 中序遍历

[中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/description/)

```c++
class Solution {
public:
void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == nullptr)
            return;
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        traversal(root, vec);
        return vec;
    }
};
```

##### 后序遍历

[后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/description/)

```c++
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
```

#### 非递归遍历

> 使用栈来模拟递归过程
> 前序，需要以**中右左**的顺序添加入栈
> 加入栈时，先将根节点放入栈中，然后放入右孩子，再加入左孩子
> 这样出栈时存储的就是中左右，即前序遍历的顺序了

##### 前序遍历

[前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/description/)

```c++
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
```

##### 后序遍历

[后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/description/)

> 相较于非递归的前序遍历，非递归的后序遍历需要将子节点入栈顺序改为**中左右**
> 这样出栈后存储的节点顺序就是中右左，然后将数组翻转一下，就得到了**左右中**的遍历顺序，即后序遍历的顺序。

``` c++
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
```

##### 中序遍历

[中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/description/)

> 在使用迭代法写中序遍历，就需要借用指针的遍历来帮助访问节点，栈则用来处理节点上的元素。
> 指针不为空 => 压栈，一直往左走
> 指针为空 => 取栈节点，存下来，往右走
> 如此循环往复，直至栈和指针都为空

```c++
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
```

#### 层序遍历

[层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

> 使用队列来辅助遍历

```c++
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
```

##### 逆层序遍历

[逆层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/)

> 将层序遍历结果reserve即可

##### 二叉树的层平均值

[二叉树的层平均值](https://leetcode.cn/problems/average-of-levels-in-binary-tree/)

> 层序时计算平均值即可

##### 二叉树的右视图

[二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/description/)

> 取层序遍历的结果中的最右值即可
> result.push_back(vec[size-1]);

##### N叉树的遍历

[N叉树的遍历](https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/)

> 添加子节点时有些许不同

```c++
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
```

##### 在每个树行中找最大值

[在每个树行中找最大值](https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/)

> 遍历每一层时比较大小，最后将每层的最大值存储即可

##### 二叉树的最大深度

[二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/)

> 返回 result.size()

##### 二叉树的最小深度

[二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

> 当找到第一个左右子节点都为空的节点时，就表明找到了最小的深度

##### 填充每个节点的下一个右侧节点指针

[填充每个节点的下一个右侧节点指针](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/description/)

> 本题依然是层序遍历，只不过在单层遍历的时候记录一下本层的头部节点，然后在遍历的时候让前一个节点指向本节点就可以了

```c++
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
```

#### 翻转二叉树

[翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/)

```c++
// 翻转二叉树
// 前序翻转二叉树
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
```

#### 对称二叉树

> 只能使用后序，左右中来遍历
> 左右获取到结果，回溯到中来进行汇总
>![Alt text](assets/image-16.png)

##### 对称二叉树

[对称二叉树](https://leetcode.cn/problems/symmetric-tree/description/)

```C++
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
```

##### 相同的树

[相同的树](https://leetcode.cn/problems/same-tree/)

```c++
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
```

[另一棵树的子树](https://leetcode.cn/problems/subtree-of-another-tree/)

> 深度暴力匹配
> 转换成深度优先搜索序列 -> kmp匹配

```c++


```

#### 二叉树的深度

##### 二叉树的最大深度

[二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

> 层序遍历解法见上文
> 使用后序遍历来解题最优
> 但严格求解深度问题还是得用前序遍历

```c++
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
```

##### 二叉树的最小深度

[二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/)

> - 层序遍历时当找到第一个左右子节点都为空的节点时，就表明找到了最小的深度
> - 递归深度遍历时要注意单边子树为空的情况
> ![最小深度](assets/image-17.png)
> **最小深度是从根节点到最近叶子节点的最短路径上的节点数量**

```c++
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
```

#### 完全二叉树的节点个数

[完全二叉树的节点个数](https://leetcode.cn/problems/count-complete-tree-nodes/)

> 一棵深度为k的有n个结点的二叉树，对树中的结点按从上至下、从左到右的顺序进行编号，如果编号为i（1≤i≤n）的结点与满二叉树中编号为i的结点在二叉树中的位置相同，则这棵二叉树称为完全二叉树。
> ![完全二叉树](assets/image-18.png)
> ![Alt text](assets/image-19.png)
> **满二叉树是完全二叉树的一种特殊形态**
> 满二叉树的结点数是**2ⁿ-1**

```c++
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
```

#### 平衡二叉树

[平衡二叉树](https://leetcode.cn/problems/balanced-binary-tree/)

> 一个二叉树每个节点的左右两个子树的高度差的绝对值不超过 1 。
> ![平衡二叉树](assets/image-20.png)
> 判断高度使用后序遍历

```c++
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
```

#### 左叶子之和

[左叶子之和](https://leetcode.cn/problems/sum-of-left-leaves/)

> 层序遍历很简单，返回最后一层第一个节点即可
>

#### 二叉树的所有路径

[二叉树的所有路径](https://leetcode.cn/problems/binary-tree-paths/)

>![二叉树所有路径](assets/image-21.png)

```c++
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
```

#### 路径总和

> 深度回溯遍历二叉树进行操作
> 注意注释处的细节问题

##### 路径总和1

[路径总和1](https://leetcode.cn/problems/path-sum/description/)

```c++
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
```

##### 路径总和2

[路径总和2](https://leetcode.cn/problems/path-sum-ii/description/)

```c++
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
```

#### 从双序合成二叉树

##### 从中序和后序遍历序列构造二叉树

[从中序和后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

> ![Alt text](assets/image-22.png)
>
> 1. 如果数组大小为零的话，说明是空节点了。
> 2. 如果不为空，那么取后序数组最后一个元素作为节点元素。
> 3. 找到后序数组最后一个元素在中序数组的位置，作为切割点。
> 4. 切割中序数组，切成中序左数组和中序右数组 （顺序别搞反了，一定是先切中序数组）
> 5. 切割后序数组，切成后序左数组和后序右数组。
> 6. 递归处理左区间和右区间。

```c++
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
```

##### 从前序和中序遍历构造二叉树

[从前序和中序遍历构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

```c++
// 从前序和中序遍历构造二叉树
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
```

#### 最大二叉树

[最大二叉树](https://leetcode.cn/problems/maximum-binary-tree/)

> 构造二叉树类题目全部前序遍历

```c++
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
```

#### 合并二叉树

[合并二叉树](https://leetcode.cn/problems/merge-two-binary-trees/)

> 同步遍历两颗二叉树
> 节点相加

```c++
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
```

#### 二叉树的最近公共祖先

[二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

> 如果左右都不为空，那此节点就是公共祖先
> ![Alt text](assets/image-24.png)
> 如果一边为空，一边不为空，那就返回不为空的节点
> ![Alt text](assets/image-25.png)
> 总过程
> ![Alt text](assets/image-26.png)

```c++
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
```

#### 二叉搜索树

##### 二叉搜索树中的搜索

[二叉搜索树中的搜索](https://leetcode.cn/problems/search-in-a-binary-search-tree/description/)

```c++
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
```

##### 验证二叉搜索树

[验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/)

> 双指针法很巧妙，pre最开始为空，然后中序赋值后一开始就是最左面（最小）的节点，然后根据递归不断中序赋值，pre就是当前root的前一个节点。
> ![Alt text](assets/image-23.png)

```c++
//验证二叉搜索树-使用数组
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
    // 指向前一个节点
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
```

##### 二叉树的最小绝对差

[二叉树的最小绝对差](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/)

> 沿用上一题思路，结合二叉搜索树的性质，使用双指针或者数组即可
> ![Alt text](assets/image-23.png)

```c++
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
```

##### 二叉搜索树中的众数

[二叉搜索树中的众数](https://leetcode.cn/problems/find-mode-in-binary-search-tree/)

```c++
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
```

##### 二叉搜索树的最小公共祖先

[二叉搜索树的最小公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)

```c++
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
```

### 并查集

## 图

### 存储结构

邻接矩阵(边多)
  
```c++
#define maxsize 100
#define inf 999999
// 邻接矩阵
struct Graph
{
    char node[maxsize];         // 顶点表, 记录顶点名字
    int edge[maxsize][maxsize]; // 邻接矩阵
    int nodeNum, edgeNum;       // 顶点数, 边数
};

/*  vector<vector<int>> vec = {
    {1, 2, 5}, {2, 3, 4}, {3, 1, 8},
    {3, 6, 9}, {4, 3, 5}, {4, 6, 6},
    {5, 4, 5}, {6, 1, 3}, {6, 5, 1} };
每个一维的数组表示一条边的信息，依次是头结点、尾结点、权值 */

Graph *create(vector<vector<int>> &vec, int nodeNum)
{
    Graph *g = new Graph;
    g->nodeNum = nodeNum;

    for (int i = 0; i < maxsize; i++)
    {
        for (int j = 0; j < maxsize; j++)
        {
            if (i == j)
                g->edge[i][j] = 0; // 对角线, 自己指自己
            else
                g->edge[i][j] = inf;
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        // 一条a->b，权值为w的边
        int a = vec[i][0];
        int b = vec[i][1];
        int w = vec[i][2];
        g->edge[a][b] = w;
        g->edgeNum++;
    }
    return g;
}

int testCreate()
{
    // 每个一维的数组表示一条边的信息，依次是头结点、尾结点、权值
    vector<vector<int>> vec = {{1, 2, 5}, {2, 3, 4}, {3, 1, 8}, {3, 6, 9}, {4, 3, 5}, {4, 6, 6}, {5, 4, 5}, {6, 1, 3}, {6, 5, 1}};
    Graph *g = create(vec, 6);
    // 打印邻接矩阵
    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        for (int j = 1; j < g->nodeNum + 1; j++)
        {
            if (g->edge[i][j] == inf)
                cout << "n";
            else
                cout << g->edge[i][j];
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}
```

邻接表(顶点多边少)

```c++
struct EdgeNode // 边表节点
{
    int b; // 节点序号
    int w; // 节点权值
    EdgeNode *next = nullptr;
};

struct HeadNode
{
    char data; // 节点信息
    EdgeNode *first = nullptr;
};

struct GraphEH
{
    HeadNode adjlist[maxsize];
    int nodeNum, edgeNum;
};

void insertEdge(HeadNode &hn, EdgeNode *en)
{
    en->next = hn.first;
    hn.first = en;
}

GraphEH *createEH(vector<vector<int>> &vec, int nodeNum)
{
    GraphEH *g = new GraphEH;
    g->nodeNum = nodeNum;

    for (int i = 0; i < vec.size(); i++)
    {
        // 一条a->b，权值为w的边
        int a = vec[i][0];
        int b = vec[i][1];
        int w = vec[i][2];

        EdgeNode *node = new EdgeNode;
        node->b = b;
        node->w = w;

        insertEdge(g->adjlist[a], node);
    }
    return g;
}

int textCreateEH()
{
    // 每个一维的数组表示一条边的信息，依次是头结点、尾结点、权值
    vector<vector<int>> vec = {{1, 2, 5}, {2, 3, 4}, {3, 1, 8}, {3, 6, 9}, {4, 3, 5}, {4, 6, 6}, {5, 4, 5}, {6, 1, 3}, {6, 5, 1}};
    GraphEH *g = createEH(vec, 6);
    // 打印邻接表
    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        cout << i;
        EdgeNode *temp = g->adjlist[i].first;
        while (temp != nullptr)
        {
            cout << " -> " << temp->b << "," << temp->w;
            temp = temp->next;
        }
        cout << endl;
    }
    return 0;
}
```

### 遍历算法

#### 深度优先遍历

![深度优先遍历](assets/image-4.png)

#### 广度优先遍历

![广度优先遍历](assets/image-10.png)

#### 连通分量的计算

> 使用深度优先搜索

### 拓扑排序

> 有向无环图的逆后序

### 最小生成树

> 图的生成树是他的一颗含有其所有顶点的无环连通子图
> 加权图的最小生成树是他的一颗权值最小的生成树

#### Prim算法

#### Kruskal算法

### 最短路径

#### Dijskall

## 排序

![排序算法](assets/image-14.png)

一些小结论：

1. 除上述之外，折半插入排序算法：最坏时间复杂度为O(n²)，平均时间复杂度O(n²)，最好时间复杂度O(nlogn)，空间O(1)，也是一种稳定的排序算法

2. 可以发现有用到二叉树思想的算法（快、堆、归），其三种情况下的时间复杂度基本都在O(nlogn)（除了快速排序在最坏情况下会退化到O(n²)）

3. 具有稳定性的算法：合插基冒（在这家店喝茶几毛钱一直是稳定的）

4. 若n较小，可采用直接插入排序或简单选择排序。又由于直接插入排序所需的记录移动次数较简单选择排序的多，因此当记录本身信息量较大时，用简单选择排序较好。

5. 若文件的初始状态已按关键字基本有序，则选用直接插入排序或冒泡排序

6. 若n较大，则应采用时间复杂度为的排序方法：快速排序、堆排序或合并排序。

7. 当待排序的关键字随机分布时，快速排序的平均时间最短，平均性能最优；但当排序的关键字基本有序或基本逆序时，会得到最坏的时间复杂度和最坏的空间复杂度

8. 堆排序所需的辅助空间少于快速排序，并且不会出现快速排序可能出现的最坏情况

9. 若要求排序稳定，并且时间复杂度为O(nlogn)，则可选用合并排序

10. 当数据量较大时，可以将合并排序和直接插入排序结合使用，先利用直接插入排序求得较长的有序子文件，然后再使用合并排序两两合并，由于两种方法都是稳定的，因此结合之后也是稳定的。

11. 当n很大，记录的关键字位数较少且可以分解时，采用基数排序较好

12. 当记录本身信息量较大时，为避免耗费大量时间移动记录，可以使用链表作为存储结构（当然，有的排序方法不适用于链表）

### 插入排序

#### 直接插入排序

> 双重for循环

```c++

```

## 回溯

组合问题，切割问题，子集问题，排列问题，棋盘问题

![回溯](assets/image-13.png)

```c
// 回溯模版
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
```

### 组合问题

> 学会将问题拆分为树形结构，找到纵向的遍历条件作为递归参数，横向条件作为for循环的参数
> 如果是在一个集合中求组合，那么递归参数就需要有startIndex， 例如组合总和，组合问题等
> 如果在两个集合中求组合，就不需要startIndex，例如电话号码组合

#### 组合

[组合](https://leetcode.cn/problems/combinations/description/)

```c++
// 组合问题
class Solution
{
public:
    vector<vector<int>> result; // 最终结果
    vector<int> combine;        // 每一层组合结果

    void backTracing(int n, int k, int startIndex)
    {
        // 递归终止条件
        if (combine.size() == k)
        {
            result.push_back(combine);
            return;
        }
        // i <= n - (k - combines.size()) + 1 剪枝
        for (int i = startIndex; i <= n; i++)
        {
            combine.push_back(i);
            backTracing(n, k, i + 1);// i+1，组合问题，防止集合数字重复
            combine.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        backTracing(n, k, 1);
        return result;
    }
};
```

#### 组合三

[组合三](https://leetcode.cn/problems/combination-sum-iii/description/)

> 在递归出口判断下总和即可, 也可以在递归时加减总和

```c++
// 在递归出口判断总和是否为n
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> combines;

    void backTracing(int k, int n, int startIndex)
    {
        if (combines.size() == k)
        {
            int sum = 0;
            for (int i = 0; i < k; i++)
            {
                sum += combines[i];
            }
            if (sum == n)
            {
                result.push_back(combines);
            }
            return;
        }

        for (int i = startIndex; i <= 9; i++)
        {
            combines.push_back(i);
            backTracing(k, n, i + 1); // 注意 i+1，不然会有重复数字出现，而题目明确要求每个数字只能使用一次
            combines.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backTracing(k, n, 1);
        return result;
    }
};

// 组合问题三， 也可以在递归过程中加减求和
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> combines;

    void backTracing(int k, int n, int startIndex, int sum)
    {
        if (combines.size() == k)
        {
            if (sum == n)
            {
                result.push_back(combines);
            }
            return;
        }

        for (int i = startIndex; i <= 9; i++)
        {
            sum += i;
            combines.push_back(i);
            backTracing(k, n, i + 1, sum);
            sum -= i;
            combines.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backTracing(k, n, 1, 0);
        return result;
    }
};
```

#### 电话号码的字母组合

[电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/)

> 递归深度由数字的多少来确定
> for循环参数由每个数字所对应的字符宽度来确定

```c++
// 电话号码的字母组合
class Solution
{
public:
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };

    vector<string> result;
    string layer;

    // 递归深度由数字的多少来确定
    void backTracing(string digits, int index)
    {
        if (index == digits.size())
        {
            result.push_back(layer);
            return;
        }

        int num = digits[index] - '0'; // 获取数字字符串中的数字
        string a = letterMap[num];     // 获取对应的文字字符
        int size = a.size();           // 横向遍历for循环的参数

        for (int i = 0; i < size; i++)
        {
            layer.push_back(a[i]);
            backTracing(digits, index + 1);
            layer.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
        {
            return result;
        }
        backTracing(digits, 0);
        return result;
    }
};
```

#### 组合总和

[组合总和](https://leetcode.cn/problems/combination-sum/)

```c++
// 组合总和
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> layer;

    // 注意，递归出口，等于大于都要退出
    // 一个集合做组合，需要startIndex，否则结果就成了全排列
    void backTracing(vector<int> &candidates, int target, int startIndex, int sum)
    {
        if (sum == target)
        {
            result.push_back(layer);
            return;
        }
        else if (sum > target)
        {
            return;
        }

        // 遍历参数就是集合大小
        for (int i = startIndex; i < candidates.size(); i++)
        {
            sum += candidates[i];
            layer.push_back(candidates[i]);
            backTracing(candidates, target, i, sum); // 因为允许选择自身，所以i不需要加一
            sum -= candidates[i];
            layer.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        if (candidates.size() == 0)
            return result;
        backTracing(candidates, target, 0, 0);
        return result;
    }
};
```

#### 组合总和2

[组合总和2](https://leetcode.cn/problems/combination-sum-ii/)

> 问题的关键在于去重
> ![Alt text](assets/image-15.png)

```c++
// 组合总和2
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> layer;

    // 在一个集合里做组合，需要startIndex
    // 递归深度是选择的数字加起来等于target的个数
    void backTracing(vector<int> &candidates, int target, int startIndex, int sum, vector<bool> used)
    {
        if (sum == target)
        {
            result.push_back(layer);
            return;
        }

        // 遍历参数是集合的大小
        // 如果数值和大于目标值，就没有必要继续遍历了
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
        {

            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过，二蛋允许同一树枝成立的
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过，再次以同一个值为起点,结果数组值就会重复
            // 要对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            sum += candidates[i];
            layer.push_back(candidates[i]);
            used[i] = true;
            backTracing(candidates, target, i + 1, sum, used); // 不允许重复选择自己，所以+1
            used[i] = false;
            layer.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<bool> used(candidates.size(), false); // 使用数组来横向去重
        sort(candidates.begin(), candidates.end());
        backTracing(candidates, target, 0, 0, used);
        return result;
    }
};
```

### 分割问题

## 贪心

- 将问题分解为若干个子问题
- 找出适合的贪心策略
- 求解每一个子问题的最优解
- 将局部最优解堆叠成全局最优解

[分发饼干](https://leetcode.cn/problems/assign-cookies/)

> for 来控制目标数组, while 来控制资源

```c++
// 分发饼干
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int index = s.size() - 1;
        int result = 0;

        for (int i = g.size() - 1; i >= 0; i--)
        {
            while (index >= 0 && s[index] >= g[i])
            {
                result++;
                index--;
                break;
            }
        }
        return result;
    }
};
```
