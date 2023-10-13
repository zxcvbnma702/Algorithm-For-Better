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

// 两两翻转链表
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {

        // 统计节点个数
        int n = 0;
        for (ListNode *cur = head; cur; cur = cur->next)
        {
            n++;
        }

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *cur = head;
        ListNode *pre = nullptr;

        // 指向翻转部分之前的一个节点的指针
        ListNode *p0 = dummyHead;
        while (n >= 2)
        {
            n -= 2;
            // 做翻转链表2的操作
            for (int i = 0; i < 2; i++)
            {
                ListNode *temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }

            // 存下反转部分链表的最后一个结点
            // 用于为下次循环之前给p0指向下次要反转部分
            // 指向翻转部分之前的一个节点做准备
            ListNode *temp = p0->next;

            // 把翻转后的部分链表的指针指正
            p0->next->next = cur;
            p0->next = pre;

            // 此时p0指向下次循环要反转的部分的前一个节点
            // 也是这次反转部分
            p0 = temp;
        }
        return dummyHead->next;
    }
};

// K个一组翻转链表
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 获取链表数目
        int n = 0;
        for (ListNode *cur = head; cur; cur = cur->next)
            ++n; // 统计节点个数

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *p0 = dummyHead;

        // 在每一个子区间里面进行翻转链表2
        // 然后将p0指向翻转完的最后一个节点
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (n >= k)
        {
            n -= k;

            for (int i = 0; i < k; i++)
            {
                ListNode *temp = cur->next;
                cur->next = pre;
                // 指针后移
                pre = cur;
                cur = temp;
            }

            // 此时p0.next 是翻转部分的最后一个结点
            // 也就是下一轮要反转的节点的前一个节点
            ListNode *next = p0->next;

            // 此时cur指向的就是翻转后的链表的后一个节点
            // 而p0.next是翻转部分链表的最后一个节点
            // 所以要给他们接上
            p0->next->next = cur;
            // pre翻转完指向的是翻转部分链表的第一个节点
            // 然后将p0.next指向pre完成翻转
            p0->next = pre;

            // 将p0指向翻转部分的最后一个结点
            // 也就是下一轮要反转的节点的前一个节点
            p0 = next;
        }

        return dummyHead->next;
    }
};

// 删除链表的倒数第n个节点
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *slow = dummyHead;
        ListNode *fast = dummyHead;

        while (n-- && fast != NULL)
        {
            fast = fast->next;
        }

        fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点

        while (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        // ListNode *tmp = slow->next;  C++释放内存的逻辑
        // slow->next = tmp->next;
        // delete nth;

        return dummyHead->next;
    }
};

// 链表香蕉
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        ListNode *curB = headB;

        int lenA = 0;
        int lenB = 0;

        // 获取链长度
        while (curA != nullptr)
        {
            curA = curA->next;
            lenA++;
        }

        while (curB != nullptr)
        {
            curB = curB->next;
            lenB++;
        }
        // 指针归位
        curA = headA;
        curB = headB;

        // 让curA为最长链表的头，lenA为其长度
        if (lenB > lenA)
        {
            swap(lenA, lenB);
            swap(curA, curB);
        }

        // 求长度差
        int gap = lenA - lenB;
        // 让curA和curB在同一起点上（末尾位置对齐）
        while (gap--)
        {
            curA = curA->next;
        }
        // 遍历curA 和 curB，遇到相同则直接返回
        while (curA != NULL)
        {
            if (curA == curB)
            {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};

// 环形链表2
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        // 快指针走两步，慢指针走一步
        //  第一次相遇后，再拿两个指针从头结点和相遇的点同步移动
        //  汇合后就是目标点

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                ListNode *index1 = head;
                ListNode *index2 = fast;

                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }

                return index1;
            }
        }
        return nullptr;
    }
};