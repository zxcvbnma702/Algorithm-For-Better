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