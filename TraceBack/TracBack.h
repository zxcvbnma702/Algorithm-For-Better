#pragma once
#include <iostream>

// 组合问题
class Solution
{
public:
    vector<vector<int>> result; // 最终结果
    vector<int> combine;        // 每一层组合结果

    void backTracing(int n, int k, int startIndex)
    {
        // 递归终止条件
        if (combine.size() == k)
        {
            result.push_back(combine);
            return;
        }

        for (int i = startIndex; i <= n; i++)
        {
            combine.push_back(i);
            backTracing(n, k, i + 1);
            combine.pop_back();
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