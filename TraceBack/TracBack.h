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
            combine.pop();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        backTracing(n, k, 1);
        return result;
    }
};