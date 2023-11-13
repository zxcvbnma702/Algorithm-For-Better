// 有效的字母异位词
bool isAnagram(char *s, char *t)
{
    int hashtable[26];
    for (int i = 0; i < 26; i++)
    {
        hashtable[i] = 0;
    }

    int i;
    while (s[i] != '\0')
    {
        hashtable[s[i] - 'a']++;
        i++;
    }

    int j;
    while (t[j] != '\0')
    {
        hashtable[t[j] - 'a']--;
        j++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (hashtable[i] != 0)
            return false;
    }

    return true;
}

// 两个数组的交集
int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int hashtable[1001] = {0};
    int lessSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int *result = (int *)malloc(sizeof(int) * lessSize);

    int index = 0;

    int i;
    for (int i = 0; i < nums1Size; i++)
    {
        hashtable[nums1[i]]++;
    }

    for (int i = 0; i < nums2Size; i++)
    {
        if (hashtable[nums2[i]] > 0)
        {
            result[index] = nums2[i];
            index++;

            hashtable[nums2[i]] = 0;
        }
    }

    *returnSize = index; // 结果数组的截止下标存下来
    return result;
}

// “快指针” 每次走两步，“慢指针” 每次走一步，当二者相等时，即为一个循环周期。此时，判断是不是因为 1 引起的循环，是的话就是快乐数，否则不是快乐数
class Solution
{
public:
    int bitSquareSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n, fast = n;
        do
        {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        } while (slow != fast);

        return slow == 1;
    }
};

int getSum(int n)
{
    int sum = 0;
    while (n)
    {
        int t = n % 10;
        sum += t * t;
        n = n / 10;
    }
    return sum;
}

bool isHappy(int n)
{
    int hashtable[820] = {0};
    int sum = getSum(n);
    while (sum != 1)
    {
        // 循环到了重复值
        if (hashtable[sum] == 1)
        {
            return false;
        }
        else
        {
            hashtable[sum]++;
        }
        sum = getSum(sum);
    }

    return true;
}
