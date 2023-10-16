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
