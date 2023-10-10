/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 移除链表元素-不使用虚拟头结点
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 没有虚拟头结点
        while (head != nullptr && head->val == val)
        {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }

        ListNode *current = head;
        while (current != nullptr && current->next != nullptr)
        {
            if (current->next->val == val)
            {
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete (temp);
            }
            else
            {
                current = current->next;
            }
        }

        return head;
    }
};

// 移除链表元素-使用虚拟头结点
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head;                // 将虚拟头结点指向head，这样方面后面做删除操作
        ListNode *cur = dummyHead;
        while (cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

// 移除链表元素-递归法
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;

        head->next = removeElements(head->next, val);

        // 递归到最后一个节点
        if (head->val == val)
        {
            return head->next;
        }
        else
        {
            return head;
        }
    }
};

// 设计链表
class MyLinkedList
{
public:
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr){};
    };

    MyLinkedList()
    {
        dummyHead = new LinkedNode(0);
        size = 0;
    }

    int get(int index)
    {
        // 非法情况
        if (index < 0 || index > size - 1)
        {
            return -1;
        }

        // temp指向虚拟头结点的下一个节点
        LinkedNode *temp = dummyHead->next;
        // 循环后正好到达index下标所指节点
        while (index)
        {
            temp = temp->next;
            index--;
        }
        return temp->val;
    }

    void addAtHead(int val)
    {
        LinkedNode *node = new LinkedNode(val);
        node->next = dummyHead->next;
        dummyHead->next = node;
        size++;
    }

    void addAtTail(int val)
    {
        // 尾插，插入到next为空的那个节点之后
        LinkedNode *node = new LinkedNode(val);
        LinkedNode *temp = dummyHead;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = node;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index < 0)
            addAtHead(val);

        LinkedNode *node = new LinkedNode(val);

        // temp指向虚拟头结点
        LinkedNode *temp = dummyHead;
        // 循环后正好到达index下标所指的前一个节点
        while (index--)
        {
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        // temp指向虚拟头结点
        LinkedNode *temp = dummyHead;
        // 循环后正好到达index下标所指的前一个节点
        while (index--)
        {
            temp = temp->next;
        }
        LinkedNode *de = temp->next;
        temp->next = temp->next->next;

        delete (de);
        de = nullptr;
        size--;
    }

private:
    LinkedNode *dummyHead;
    int size;
};

// 翻转链表-双指针
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp;
        ListNode *pre = nullptr;
        ListNode *cur = head;

        while (cur)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        return pre;
    }
};

// 翻转链表-递归法
class Solution
{
public:
    ListNode *traverse(ListNode *pre, ListNode *cur)
    {
        if (cur == nullptr)
            return pre;

        ListNode *temp = cur->next;

        cur->next = pre;
        // 用递归来代替迭代中指针的后移
        // 如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return traverse(cur, temp);
    }

    ListNode *reverseList(ListNode *head)
    {
        // 和双指针法初始化是一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return traverse(nullptr, head);
    }
};

// 反转链表2
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *p0 = dummyHead;

        // 到达了翻转的前一个节点
        for (int i = 0; i < left - 1; i++)
        {
            p0 = p0->next;
        }

        // 把这一段当成悬空的来翻转
        ListNode *pre = nullptr;
        ListNode *cur = p0->next;
        for (int i = 0; i < right - left + 1; i++)
        {
            ListNode *temp = cur->next;
            cur->next = pre;

            // 后移
            pre = cur;
            cur = temp;
        }

        // 此时cur指向的就是翻转后的后一个节点
        p0->next->next = cur;
        // 此时pre就是翻转后的链表的头节点
        p0->next = pre;

        return dummyHead->next;
    }
};