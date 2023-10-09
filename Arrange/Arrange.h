#pragma once
#include <iostream>

// 二分查找
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        // 当left==right，区间[left, right]依然有效，所以用 <=
        while (left <= right)
        {
            // 防止溢出 等同于(left + right)/2
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target)
            {
                // target 在左区间，所以[left, middle - 1]
                right = middle - 1;
            }
            else if (nums[middle] < target)
            {
                // target 在右区间，所以[middle + 1, right]
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};

// 移除元素
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int slow = 0;
        // 快指针寻找和目标值不相等的元素
        for (int fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

// 有序数组的平方
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;)
        { // 注意这里要i <= j，因为最后要处理两个元素
            if (A[i] * A[i] < A[j] * A[j])
            {
                result[k--] = A[j] * A[j];
                j--;
            }
            else
            {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};

// 长度最小的子数组
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;
        int sum = 0;
        int len = 0; // 子序列长度
        int result = INT32_MAX;
        for (int right = 0; right < nums.size(); right++)
        {
            // 累计目标值
            sum += nums[right];
            // 当大于目标值，移动左指针
            while (sum >= target)
            {
                len = right - left + 1;    // 获取区间长度
                sum -= nums[left];         // 缩减总和值
                left++;                    // 左指针右移
                result = min(len, result); // 保存最小的长度区间值
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

// 螺旋矩阵2
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int t = 0;     // top
        int b = n - 1; // bottom
        int l = 0;     // left
        int r = n - 1; // right
        vector<vector<int>> ans(n, vector<int>(n));
        // for循环中变量定义成i或j的细节：按照通常的思维，i代表行，j代表列
        // 这样，就可以很容易区分出来变化的量应该放在[][]的第一个还是第二个
        // 对于变量的边界怎么定义：
        // 从左向右填充：填充的列肯定在[left,right]区间
        // 从上向下填充：填充的行肯定在[top,bottom]区间
        // 从右向左填充：填充的列肯定在[right,left]区间
        // 从下向上填充：填充的行肯定在[bootom,top]区间
        // 通过上面的总结会发现边界的起始和结束与方向是对应的
        int k = 1;

        while (k <= n * n)
        {
            // 从左到右填充，相当于缩小上边界
            for (int i = l; i <= r; ++i, ++k)
                ans[t][i] = k;
            // 缩小上边界
            ++t;
            // 从上向下填充，相当于缩小右边界
            for (int i = t; i <= b; ++i, ++k)
                ans[i][r] = k;
            // 缩小右边界
            --r;
            // 从右向左填充，相当于缩小下边界
            for (int i = r; i >= l; --i, ++k)
                ans[b][i] = k;
            // 缩小下边界
            --b;
            // 从下向上填充，相当于缩小左边界
            for (int i = b; i >= t; --i, ++k)
                ans[i][l] = k;
            // 缩小左边界
            ++l;
        }
        return ans;
    }
};