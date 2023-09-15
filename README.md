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
> ![Alt text](image.png)
>
> 二叉树转换为树
>
> 1. 将二叉树从左上到右下分为若干层。然后调整成水平方向
> 2. 找到每一层节点在其上一层的父节点，加线
> 3. 去除兄弟节点之间的连线
>
> ![Alt text](image-2.png)
>
> 二叉树转换为森林
>
> 前提: 加入一棵二叉树的根节点有右孩子，则这棵二叉树能够转换为森林，否则转换为一棵树。
> ![Alt text](image-3.png)
>
> 1. 从根节点开始，若右孩子存在，则把与右孩子结点的连线删除。再查看分离后的二叉树，若其根节点的右孩子存在，则连续删除。直到所有这些根结点与右孩子的连线都删除为止。
> 2. 将每棵分离后的二叉树转换为树。
> ![Alt text](image-5.png)
>
> 森林转换为二叉树
>
> 1. 第一步每棵树自己先成为一课二叉树
> ![给兄弟加线](image-6.png)
> ![去线](image-7.png)
> ![儿子在左，兄弟在右](image-8.png)
> 2. 从第二棵二叉树开始，每棵二叉树都是上一个二叉树根节点的右孩子
> ![森林转二叉树](image-9.png)

### 二叉树

> 完全二叉树 使用顺序存储 fabulous
>

#### 递归遍历

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
> 中左右
> 加入栈时，先将根节点放入栈中，然后放入右孩子，再加入左孩子
> 这样出栈时存储的就是中左右，即前序遍历的顺序了

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

[后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/description/)

> 相较于非递归的前序遍历， 非递归的后序遍历需要将子节点入栈顺序改为中左右
> 这样出栈后存储的节点顺序就是中右左， 然后将数组翻转一下，就得到了左右中的遍历顺序, 即后序遍历的顺序。

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

[中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/description/)

> 在使用迭代法写中序遍历，就需要借用指针的遍历来帮助访问节点，栈则用来处理节点上的元素。
> 指针不为空 => 压栈， 一直往左走
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

[逆层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/)

> 将层序遍历结果reserve即可

[二叉树的层平均值](https://leetcode.cn/problems/average-of-levels-in-binary-tree/)

> 层序时计算平均值即可

[二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/description/)

> 取层序遍历的结果中的最右值即可
> result.push_back(vec[size-1]);

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

[在每个树行中找最大值](https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/)

> 遍历每一层时比较大小，最后将每层的最大值存储即可

[二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/)

> 返回 result.size()

[二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

> 当找到第一个左右子节点都为空的节点时，就表明找到了最小的深度

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
```

#### 对称二叉树



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

![深度优先遍历](image-4.png)

#### 广度优先遍历

![广度优先遍历](image-10.png)

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

## 回溯

组合问题，切割问题，子集问题，排列问题，棋盘问题

![回溯](image-13.png)

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
            backTracing(n, k, i + 1);
            combine.pop();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        backTracing(n, k, 1);
        return result;
    }
};
```

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