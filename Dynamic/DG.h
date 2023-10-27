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