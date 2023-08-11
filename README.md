# Algorithm-For-Better

为了考研,努力刷题

## 线性表课后习题

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
