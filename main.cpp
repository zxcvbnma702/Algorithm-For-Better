#include <iostream>
#include <vector>
#include "Sort/Sort.h"

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

int myKMP(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    // 计算next数组
    vector<int> next(M);
    next[0] = 0;
    // 起始时, next[0] = 0, j begin with 0, i begin with 1
    // i 的作用是遍历目标串, 每次循环确定next[i]的值
    for (int i = 1, j = 0; i < M; i++)
    {
        // 如果pat[i] != pat[j], 就将j指针指向前一位置的next数组所对应的值, 即j = next[j - 1]
        // 这一过程循环进行直到 j == 0 或者 pat[i] == pat[j]
        // 当pat[i] != pat[j]时, 不断前移, 去寻找使得前 0 ~ j 个字符为对应的pat[i]的尽可能大的相等前后缀
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
                j = next[j - 1];
            }
        }
    }

    if (j == M)
        return i - j;
    return -1;
}

int main()
{
    // Node *head = new Node;
    // vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    // head = initList(head, a);

    // reserseList(head);

    // Node *it = head->next;
    // while (it != nullptr)
    // {
    //     cout << it->data << " ";
    //     it = it->next;
    // }

    // int result = myKMP("tsa", "sadbutsad");
    insertDriect();
    // testCreate();
    // testCreateEH();
    return 0;
}