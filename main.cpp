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
    将left暂存起来,作为转换后的主体链
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

int main()
{
    Node *head = new Node;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    head = initList(head, a);

    reserseList(head);

    Node *it = head->next;
    while (it != nullptr)
    {
        cout << it->data << " ";
        it = it->next;
    }

    return 0;
}