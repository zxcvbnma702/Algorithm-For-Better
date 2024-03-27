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

// 移动零
class Solution
{
public:
    // 直接将0去掉, 然后在后面补零
    void moveZeroes(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;

        while (fast < nums.size())
        {
            if (nums[fast] != 0)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        for (int i = slow; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};

// 盛最多雨水的容器
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;

        // 面积 = （right - left）* min(height[left], height[right])
        while (left < right)
        {
            int area = (right - left) * min(height[left], height[right]);
            result = max(result, area);

            // 向内移动高的板子，area一定会变小
            // 向内移动低的板子, area可能会变大
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return result;
    }
};

// 接雨水-暴力解法
class Solution
{
public:
    // 如果按照列来计算的话，宽度一定是1了，我们再把每一列的雨水的高度求出来就可以了。
    // 三指针, 找到每一列左右最高的那一排, 然后取其中低的一个减去中间的排数计算

    int trap(vector<int> &height)
    {

        int result = 0;

        for (int i = 0; i < height.size(); i++)
        {
            // 边缘无雨水
            if (i == 0 || i == height.size() - 1)
            {
                continue;
            }

            // 寻找指针左右两边的最大高度
            int rHeight = height[i + 1];
            int lHeight = height[i - 1];

            for (int r = i + 1; r < height.size(); r++)
            {
                if (height[r] > rHeight)
                    rHeight = height[r];
            }

            for (int l = i - 1; l >= 0; l--)
            {
                if (height[l] > lHeight)
                    lHeight = height[l];
            }

            // 注意只有h大于零的时候，在统计到总和中
            int h = min(lHeight, rHeight) - height[i];
            if (h > 0)
                result += h;
        }
        return result;
    }
};

// 接雨水-双指针优化
class Solution
{
public:
    // 将每一个位置的最大高度用数组给存下来,避免了重复的计算
    int trap(vector<int> &height)
    {
        int result = 0;

        // 两根柱子无法接雨水
        if (height.size() <= 2)
            return 0;

        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);

        // 分别计算左边最大高度
        maxLeft[0] = height[0];
        for (int i = 1; i < height.size(); i++)
        {
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
        }
        // 分别计算右边最大高度
        maxRight[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--)
        {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }

        // area = min(maLeft, maxRight) - height
        for (int i = 0; i < height.size(); i++)
        {
            int h = min(maxLeft[i], maxRight[i]) - height[i];
            if (h > 0)
                result += h;
        }

        return result;
    }
};

// 合并区间
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size();)
        {
            // 用于存储最右边界
            int tempMax = intervals[i][1];

            int j = i + 1;

            while (j < intervals.size() && intervals[j][0] <= tempMax)
            {
                tempMax = max(tempMax, intervals[j][1]);
                j++;
            }
            result.push_back({intervals[i][0], tempMax});
            i = j;
        }
        return result;
    }
};

// 旋转数组
class Solution
{
public:
    void reverse(vector<int> &nums, int left, int right)
    {
        while (left < right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    void rotate(vector<int> &nums, int k)
    {

        k %= nums.size();

        // 首先全局翻转
        reverse(nums, 0, nums.size() - 1);
        // 各自翻转
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

// 除自身以外数组的乘积
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int len = nums.size();
        if (len == 0)
            return {};

        vector<int> result(len, 1);

        result[0] = 1;
        int temp = 1;

        for (int i = 1; i < len; i++)
        {
            result[i] = result[i - 1] * nums[i - 1];
        }
        for (int i = len - 2; i >= 0; i--)
        {
            temp *= nums[i + 1];
            result[i] *= temp;
        }
        return result;
    }
};

// 第一个缺失的正数
class Solution
{
public:
    // 对于一个长度为 NNN 的数组，其中没有出现的最小正整数只能在 [1,N+1]中。
    int firstMissingPositive(vector<int> &nums)
    {
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            while (nums[i] > 0 && nums[i] <= len &&
                   nums[nums[i] - 1] != nums[i])
            {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < len; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return len + 1;
    }
};