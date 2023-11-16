#pragma once
#include <iostream>

// 组合问题
class Solution
{
public:
    vector<vector<int>> result; // 最终结果
    vector<int> combines;       // 每一层组合结果

    void backTracing(int n, int k, int startIndex)
    {
        // 递归终止条件
        if (combines.size() == k)
        {
            result.push_back(combines);
            return;
        }

        // for循环用来进行树的横向遍历
        for (int i = startIndex; i <= n - (k - combines.size()) + 1; i++)
        {
            combines.push_back(i);
            // 递归进行树的纵向遍历
            backTracing(n, k, i + 1); // i+1 是为了防止出现[1, 1] 类似情况
            combines.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        backTracing(n, k, 1);
        return result;
    }
};

// 组合问题三
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> combines;

    void backTracing(int k, int n, int startIndex, int sum)
    {
        if (combines.size() == k)
        {
            if (sum == n)
            {
                result.push_back(combines);
            }
            return;
        }

        for (int i = startIndex; i <= 9; i++)
        {
            sum += i;
            combines.push_back(i);
            backTracing(k, n, i + 1, sum);
            sum -= i;
            combines.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backTracing(k, n, 1, 0);
        return result;
    }
};

class Solution
{
public:
    vector<vector<int>> result;
    vector<int> combines;

    void backTracing(int k, int n, int startIndex)
    {
        if (combines.size() == k)
        {
            int sum = 0;
            for (int i = 0; i < k; i++)
            {
                sum += combines[i];
            }
            if (sum == n)
            {
                result.push_back(combines);
            }
            return;
        }

        for (int i = startIndex; i <= 9; i++)
        {

            combines.push_back(i);
            backTracing(k, n, i + 1);
            combines.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backTracing(k, n, 1);
        return result;
    }
};

class Solution
{
public:
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };

    vector<string> result;
    string layer;

    // 递归深度由数字的多少来确定
    void backTracing(string digits, int index)
    {
        if (index == digits.size())
        {
            result.push_back(layer);
            return;
        }

        int num = digits[index] - '0'; // 获取数字字符串中的数字
        string a = letterMap[num];     // 获取对应的文字字符
        int size = a.size();           // 横向遍历for循环的参数

        for (int i = 0; i < size; i++)
        {
            layer.push_back(a[i]);
            backTracing(digits, index + 1);
            layer.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
        {
            return result;
        }
        backTracing(digits, 0);
        return result;
    }
};

// 组合总和
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> layer;

    // 注意，递归出口，等于大于都要退出
    // 一个集合做组合，需要startIndex，否则结果就成了全排列
    void backTracing(vector<int> &candidates, int target, int startIndex, int sum)
    {
        if (sum == target)
        {
            result.push_back(layer);
            return;
        }
        else if (sum > target)
        {
            return;
        }

        // 遍历参数就是集合大小
        for (int i = startIndex; i < candidates.size(); i++)
        {
            sum += candidates[i];
            layer.push_back(candidates[i]);
            backTracing(candidates, target, i, sum); // 因为允许选择自身，所以i不需要加一
            sum -= candidates[i];
            layer.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        if (candidates.size() == 0)
            return result;
        backTracing(candidates, target, 0, 0);
        return result;
    }
};

// 组合总和2
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> layer;

    // 在一个集合里做组合，需要startIndex
    // 递归深度是选择的数字加起来等于target的个数
    void backTracing(vector<int> &candidates, int target, int startIndex, int sum, vector<bool> used)
    {
        if (sum == target)
        {
            result.push_back(layer);
            return;
        }

        // 遍历参数是集合的大小
        // 如果数值和大于目标值，就没有必要继续遍历了
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
        {

            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过，二蛋允许同一树枝成立的
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过，再次以同一个值为起点,结果数组值就会重复
            // 要对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            sum += candidates[i];
            layer.push_back(candidates[i]);
            used[i] = true;
            backTracing(candidates, target, i + 1, sum, used); // 不允许重复选择自己，所以+1
            used[i] = false;
            layer.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<bool> used(candidates.size(), false); // 使用数组来横向去重
        sort(candidates.begin(), candidates.end());
        backTracing(candidates, target, 0, 0, used);
        return result;
    }
};

// 子集
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> row;

    void backTracing(vector<int> &nums, int startIndex)
    {
        result.push_back(row);

        for (int i = startIndex; i < nums.size(); i++)
        {
            row.push_back(nums[i]);
            backTracing(nums, i + 1);
            row.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        backTracing(nums, 0);
        return result;
    }
};