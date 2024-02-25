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

// 有效的字母异位词 c++
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int hashTable[26] = {0};

        for (int i = 0; i < s.size(); i++)
        {
            hashTable[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++)
        {
            hashTable[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (hashTable[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};

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

// 两个数组的交集-c++
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int hashTable[1000] = {0};

        vector<int> result;
        for (int i = 0; i < nums1.size(); i++)
        {
            hashTable[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (hashTable[nums2[i]] != 0)
            {
                // 如果找到了重复的元素, 将其加入进结果数组
                result.push_back(nums2[i]);
                // 然后将重复元素置0, 防止重复
                hashTable[nums2[i]] = 0;
            }
        }

        return result;
    }
};

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

class Solution
{
public:
    int getNUm(int sum)
    {
        int result = 0;

        while (sum)
        {
            int a = sum % 10;
            result += a * a;
            sum = sum / 10;
        }
        return result;
    }

    bool isHappy(int n)
    {
        // 无序集合
        unordered_set<int> set;

        while (1)
        {
            int sum = getNUm(n);
            // 快乐数
            if (sum == 1)
                return true;

            // 找到了重复值,代表进入了无限循环
            if (set.find(sum) != set.end())
            {
                return false;
            }
            else
            {
                set.insert(sum); // 没找到,加入到集合中
            }

            n = sum;
        }
    }
};

// 两数之和-map查找
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = map.find(target - nums[i]);
            // 找到了另一个数
            if (iter != map.end())
            {
                return {i, iter->second};
            }

            // 将数值插入无序map
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

// 四数相加
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                     vector<int> &nums4)
    {
        unordered_map<int, int> map1;
        // 返回的是元组的数量
        int result = 0;

        // 将前两个集合可能出现的值做统计 ,所以使用map
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                map1[a + b]++;
            }
        }

        for (int c : nums3)
        {
            for (int d : nums4)
            {
                // 寻找到一个符合条件的元组
                auto iter = map1.find(0 - (c + d));
                if (iter != map1.end())
                {
                    // second pair第二个
                    result += iter->second;
                }
            }
        }
        return result;
    }
};

// 三数之和
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;

        // 排序
        sort(nums.begin(), nums.end());

        // 用for循环的i作为一个指针
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                return result; // 不可能等于0了

            // 对这个指针进行去重操作, 值重复了就让指针往右走
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // 每层循环里再使用双指针左右逼近值0
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[right] + nums[left] > 0)
                {
                    right--;
                }
                else if (nums[i] + nums[right] + nums[left] < 0)
                {
                    left++;
                }
                else
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;

                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};

// 四数之和
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        // 第一指针
        for (int k = 0; k < nums.size(); k++)
        {
            // 大于0时再进行剪枝
            if (nums[k] >= 0 && nums[k] > target)
            {
                break;
            }

            // 第一指针去重
            if (k > 0 && nums[k] == nums[k - 1])
            {
                continue;
            }

            // 第二指针
            for (int i = k + 1; i < nums.size(); i++)
            {
                // 大于0时再进行剪枝
                if (nums[i] + nums[k] >= 0 && nums[i] + nums[k] > target)
                {
                    break;
                }
                // 第二指针去重
                if (i > k + 1 && nums[i] == nums[i - 1])
                {
                    continue;
                }

                // 第三指针
                int a = i + 1;
                // 第四指针
                int b = nums.size() - 1;
                while (a < b)
                {
                    if ((long)nums[k] + nums[i] + nums[a] + nums[b] < target)
                    {
                        a++;
                    }
                    else if ((long)nums[k] + nums[i] + nums[a] + nums[b] >
                             target)
                    {
                        b--;
                    }
                    else
                    {
                        result.push_back(
                            vector<int>{nums[k], nums[i], nums[a], nums[b]});

                        // 第三指针去重
                        while (a < b && nums[a] == nums[a + 1])
                            a++;
                        // 第四指针去重
                        while (a < b && nums[b] == nums[b - 1])
                            b--;

                        a++;
                        b--;
                    }
                }
            }
        }
        return result;
    }
};

// 字母异位词分组
class Solution
{
public:
    // 排完序的异位词作为键, 出现次序作为值
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        map<string, int> hashTable;

        // 异位词的数量,充当二维数组的行指针
        int count = 0;

        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());

            // 没找到异位词, 就将其加入到新的一列结果中
            if (hashTable.find(strs[i]) == hashTable.end())
            {
                result.push_back(vector<string>());
                result.back().push_back(temp);
                // 表明这是第几个异位词, 方便后期插入到对应的词数组里
                hashTable[strs[i]] = count;
                count++;
            }
            else // 找到异位词, 就将他加入到对应集合里
            {    // 从map的值中获取插入位置
                int index = hashTable[strs[i]];
                result[index].push_back(temp);
            }
        }
        return result;
    }
};

// 最长连续序列
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set;

        int result = 0;
        // 使用set集合去重
        for (int i = 0; i < nums.size(); i++)
        {
            set.insert(nums[i]);
        }

        // 查找元素的最左边界数
        for (int i = 0; i < nums.size(); i++)
        {
            if (set.count(nums[i] - 1))
                continue;

            // 到达最左边界数
            int count = 1;

            // 向最右边界计数
            while (set.count(nums[i] + 1))
            {
                count++;
                // 循环右移
                nums[i]++;
            }
            result = max(result, count);
        }
        return result;
    }
};