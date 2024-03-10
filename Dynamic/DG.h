// 斐波那契数
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;

        // dp数组的意义就是第n个斐波那契数的值
        vector<int> dp(n + 1, 0);

        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// 爬楼梯
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return n;

        // dp[i]： 爬到第i层楼梯，有dp[i]种方法
        vector<int> dp(n + 1, 0);

        // dp数组初始化
        dp[0] = 1;
        dp[1] = 1;

        // 从递推公式dp[i] = dp[i - 1] + dp[i - 2];中可以看出，遍历顺序一定是从前向后遍历的
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// 使用最小花费爬楼梯
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size() + 1);

        // 一开始0阶1阶不花钱
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= cost.size(); i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[cost.size()];
    }
};

// 不同路径-递归
class Solution
{
public:
    int traverse(int i, int j, int m, int n)
    {
        if (i > m || j > n)
            return 0;
        if (i == m && j == n)
            return 1;
        return traverse(i + 1, j, m, n) + traverse(i, j + 1, m, n);
    }

    int uniquePaths(int m, int n)
    {
        return traverse(1, 1, m, n);
    }
};

// 不同路径-二维dp
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // dp数组代表了到达这一点的路径条数
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 机器人只能向下右移动 所以递推公式dp[i, j] = dp[i-1, j] + dp[i, j-1]
        // 第一行和第一列路径条数都是1
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;

        // 遍历顺序 从左上到右下
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

// 不同路径2
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) // 如果在起点或终点出现了障碍，直接返回0
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++)
            dp[0][j] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

// 整数拆分
class Solution
{
public:
    int integerBreak(int n)
    {

        // dp数组代表了第i个数的拆分最大值
        vector<int> dp(n + 1);
        dp[2] = 1;

        // 先知道前面的值,后面递推更大的数的时候会用到
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i - 1; j++)
            {
                // 一个是j * (i - j) 直接相乘; 一个是j * dp[i - j]，相当于是拆分(i - j)
                // 简单的数j*(i-j)就完成了拆分
                // 复杂的数利用之前拆分好的数dp[i]来减少计算量
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};

// 不同的二叉搜索树
class Solution
{
public:
    int numTrees(int n)
    {
        // dp[i]数组表示的是由i个节点所组成的二叉搜索树的种数
        int dp[n + 1];

        memset(dp, 0, sizeof(dp));

        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                // j-1 为j为头结点左子树节点数量，i-j 为以j为头结点右子树节点数量
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};

// 最大子序和
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        vector<int> dp(nums.size());

        dp[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
            if (dp[i] > result)
                result = dp[i];
        }

        return result;
    }
};