// 用栈实现队列
class MyQueue
{
public:
    stack<int> stIn;
    stack<int> stOut;

    MyQueue()
    {
    }

    void push(int x)
    {
        stIn.push(x);
    }

    int pop()
    {
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if (stOut.empty())
        {
            // 从stIn导入数据直到stIn为空
            while (!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    int peek()
    {
        int result = this->pop();
        stOut.push(result);
        return result;
    }

    bool empty()
    {
        return stOut.empty() && stIn.empty();
    }
};

// 用队列实现栈
class MyStack
{
public:
    queue<int> que;

    MyStack()
    {
    }

    void push(int x)
    {
        que.push(x);
    }

    int pop()
    {
        int size = que.size();
        while (size > 1)
        {
            que.push(que.front());
            que.pop();
            size--;
        }
        int result = que.front();
        que.pop();
        return result;
    }

    int top()
    {
        int re = this->pop();
        que.push(re);
        return re;
    }

    bool empty()
    {
        return que.empty();
    }
};

// 有效的括号
class Solution
{
public:
    bool isValid(string s)
    {
        // 如果是奇数，括号肯定不匹配
        if (s.size() % 2 != 0)
            return false;

        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(')');
            else if (s[i] == '{')
                st.push('}');
            else if (s[i] == '[')
                st.push(']');
            // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
            // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
            else if (st.empty() || s[i] != st.top())
                return false;
            else
                st.pop();
        }

        // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
        return st.empty();
    }
};

// 删除字符串的所有相邻重复项
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty() || s[i] != st.top())
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }

        string result = "";
        while (!st.empty())
        { // 将栈中元素放到result字符串汇总
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        // 力扣修改了后台测试数据，需要用longlong
        stack<long long> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (tokens[i] == "+")
                    st.push(num2 + num1);
                if (tokens[i] == "-")
                    st.push(num2 - num1);
                if (tokens[i] == "*")
                    st.push(num2 * num1);
                if (tokens[i] == "/")
                    st.push(num2 / num1);
            }
            else
            {
                st.push(stoll(tokens[i]));
            }
        }

        int result = st.top();
        st.pop(); // 把栈里最后一个元素弹出（其实不弹出也没事）
        return result;
    }
};

// 单调队列
class MyQueue
{
public:
    deque<int> que;

    void pop(int value)
    {
        if (!que.empty() && value == que.front())
        {
            que.pop_front();
        }
    }

    void push(int value)
    {
        while (!que.empty() && value > que.back())
        {
            que.pop_back();
        }
        que.push_back(value);
    }

    int front()
    {
        return que.front();
    }
}

// 滑动窗口最大值
class Solution
{
private:
    class MyQueue
    { // 单调队列（从大到小）
    public:
        deque<int> que; // 使用deque来实现单调队列
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int value)
        {
            if (!que.empty() && value == que.front())
            {
                que.pop_front();
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value)
        {
            while (!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }
        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front()
        {
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++)
        { // 先将前k的元素放进队列
            que.push(nums[i]);
        }
        result.push_back(que.front()); // result 记录前k的元素的最大值
        for (int i = k; i < nums.size(); i++)
        {
            que.pop(nums[i - k]);          // 滑动窗口移除最前面元素
            que.push(nums[i]);             // 滑动窗口前加入最后面的元素
            result.push_back(que.front()); // 记录对应的最大值
        }
        return result;
    }
};

template <typename Key>
class MaxPQ
{
private:
    // 存储元素的数组
    Key *pq;
    // 当前Priority Queue中的元素个数
    int size = 0;

public:
    MaxPQ(int cap)
    {
        // 索引0不用，所以多分配一个空间
        pq = new Key[cap + 1];
    }

    // 返回当前队列中最大元素
    Key max()
    {
        return pq[1];
    }

    // 插入元素e
    void insert(Key e)
    {
        size++;
        // 先把新元素加到最后
        pq[size] = e;
        // 然后让它上浮到正确的位置
        swim(size);
    }

    // 删除并返回当前队列中最大元素
    Key delMax()
    {
        // 最大堆的堆顶就是最大元素
        Key max = pq[1];
        // 把这个最大元素换到最后，删除之
        swap(1, size);
        pq[size] = nullptr;
        size--;
        // 让 pq[1] 下沉到正确位置
        sink(1);
        return max;
    }

private:
    // 交换数组的两个元素
    void swap(int i, int j)
    {
        Key temp = pq[i];
        pq[i] = pq[j];
        pq[j] = temp;
    }

    // pq[i]是否比pq[j]小？
    bool less(int i, int j)
    {
        return pq[i] < pq[j];
    }

    // 上浮第x个元素，以维护最大堆性质
    void swim(int x)
    {
        while (x > 1 && parent[x] < x)
        {
            swap(parent(x), x);
            x = parent(x);
        }
    }

    // 下沉第x个元素，以维护最大堆性质
    void sink(int x)
    {
        while (left(x) <= size)
        {
            // 先假设左边节点较大
            int max = left(x);
            // 如果右边节点存在，比一下大小
            if (right(x) <= size && less(max, right(x)))
                max = right(x);
            // 结点 x 比俩孩子都大，就不必下沉了
            if (less(max, x))
                break;
            // 否则，不符合最大堆的结构，下沉 x 结点
            swap(x, max);
            x = max;
        }
    }

public:
    // 还有left, right, parent三个方法
    //  父节点的索引
    int parent(int root)
    {
        return root / 2;
    }
    // 左孩子的索引
    int left(int root)
    {
        return root * 2;
    }
    // 右孩子的索引
    int right(int root)
    {
        return root * 2 + 1;
    }
};
