// 翻转字符串
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
};

// 翻转字符串2
class Solution
{
public:
    void reverse(string &s, int start, int end)
    {
        for (int i = start, j = end - 1; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }

    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            // 如果剩余字符小于 2k 但大于或等于 k 个
            // 则反转前 k 个字符，其余字符保持原样。
            if (i + k <= s.size())
            {
                reverse(s, i, i + k);
                continue;
            }
            // 如果剩余字符少于 k 个，则将剩余字符全部反转。
            reverse(s, i, s.size());
        }
        return s;
    }
};

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        string S = haystack;
        string T = needle;
        int n = S.size(), m = T.size();

        vector<int> fail(m); // fail数组
        fail[0] = -1;        // 起始时，先将fail[0]赋为-1

        // 当j == 0，且T[i] != T[j]时，就说明无相等前后缀，最大相等前后缀长度为0
        for (int i = 1, j = 0; i < m; i++)
        {
            // 如果T[i] != T[j]，就将j指针指向前一位置的fail数组所对应的值，即j = fail[j - 1] + 1
            while (j > 0 && T[i] != T[j])
                j = fail[j - 1] + 1;

            // 如果T[i] == T[j]，就令fail[i] = j，指针i和j同时后移
            if (T[i] == T[j])
            {
                fail[i] = j;
                j++;
            }
            // 如果j == 0，且T[i] != T[j]，说明不存在相等前后缀
            else
            {
                fail[i] = -1;
            }
        }

        // 以下为kmp匹配过程
        int i = 0, j = 0; // i是主串S中的指针，j是模式串T中的指针
        while (i < n && j < m)
        {
            if (S[i] == T[j])
            {
                i++;
                j++;
            }
            else
            {
                // 如果主串S中的S[i]与串T中的第一个字符T[0]就匹配失败，那么主串中的指针i直接移动到下一位
                if (j == 0)
                    i++;
                else
                {
                    j = fail[j - 1] + 1;
                }
            }
        }
        // 这里可以这么想：如果主串的第一个子串就匹配成功的话，那么最终i和j的值是相等的，于是返回的下标是i - j
        if (j == m)
        {
            return i - j;
        }
        return -1;
    }
};

// 翻转字符串里的单词
class Solution
{
public:
    // 移除元素
    void removeExtraSpace(string &s)
    {
        int slow = 0;
        for (int i = 0; i < s.size(); ++i)
        { //
            if (s[i] != ' ')
            { // 遇到非空格就处理，即删除所有空格。
                if (slow != 0)
                    s[slow++] = ' '; // 手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (i < s.size() && s[i] != ' ')
                { // 补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); // slow的大小即为去除多余空格后的大小。
    }

    void reverse(string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s)
    {
        // 首先移除空格，思路同移除元素
        removeExtraSpace(s);

        // 整体翻转一遍
        reverse(s, 0, s.size() - 1);

        // 对子单词进行翻转
        // removeExtraSpaces后保证第一个单词的开始下标一定是0
        int start = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            // 到达空格或者串尾，说明一个单词结束。进行翻转。
            if (s[i] == ' ' || i == s.size())
            {
                // 翻转，注意是左闭右闭 []的翻转。
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};

// 重复的子字符串
class Solution
{
public:
    void getNext(int *next, const string &s)
    {
        next[0] = -1;
        int j = -1;
        for (int i = 1; i < s.size(); i++)
        {
            while (j >= 0 && s[i] != s[j + 1])
            {
                j = next[j];
            }
            if (s[i] == s[j + 1])
            {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s)
    {
        if (s.size() == 0)
        {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0)
        {
            return true;
        }
        return false;
    }
};

// 回文子串-暴力算法
class Solution
{
public:
    bool isPalindrome(string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    int countSubstrings(string s)
    {
        // 单个字符也是回文子串 "a"
        int result = s.size();

        for (int i = 0; i < s.size(); i++)
        {
            // 取一种极端情况 0 + n
            for (int j = 2; i + j - 1 < s.size(); j++)
            {
                if (isPalindrome(s, i, i + j - 1))
                    result++;
            }
        }
        return result;
    }
};

// 回文子串-中心扩展法
class Solution
{
public:
    int extend(string &s, int left, int right)
    {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s)
    {
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            result += extend(s, i, i);
            result += extend(s, i, i + 1);
        }
        return result;
    }
};