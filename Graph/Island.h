// 岛屿数量-淹岛法
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int result = 0;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    result++;
                    dfs(grid, i, j);
                }
            }
        }

        return result;
    }

    // 将相邻岛屿全部淹没
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        // 边界条件
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return;
        }

        // 到达水面，不需要淹岛
        if (grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};

// 封闭岛屿的数量
class Solution
{
public:
    // 将外层岛屿淹没掉, 然后再使用淹岛法即可
    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;

        // 淹没上下边界
        for (int i = 0; i < n; i++)
        {
            dfs(grid, 0, i);
            dfs(grid, m - 1, i);
        }
        // 淹没左右边界
        for (int i = 0; i < m; i++)
        {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    result++;
                    // 淹没相邻陆地
                    dfs(grid, i, j);
                }
            }
        }
        return result;
    }

    // 淹岛法
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        // 触底条件
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;

        // 水跳过
        if (grid[i][j] == 1)
            return;

        // 淹没
        grid[i][j] = 1;

        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};

// 飞地数量
class Solution
{
public:
    // 将外面的岛淹掉, 剩下的陆地就都是飞地了
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;

        // 淹掉上下边界
        for (int i = 0; i < n; i++)
        {
            dfs(grid, 0, i);
            dfs(grid, m - 1, i);
        }
        // 淹掉左右边界
        for (int i = 0; i < m; i++)
        {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    result++;
            }
        }

        return result;
    }

    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        // 边界条件
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;

        if (grid[i][j] == 0)
        {
            return;
        }

        grid[i][j] = 0;

        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};

// 最大岛屿面积-带返回值的淹岛法
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    result = max(result, dfs(grid, i, j));
                }
            }
        }
        return result;
    }

    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        // 边界条件
        if (i < 0 || j < 0 || i >= m || j >= n)
            return 0;

        if (grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;

        return dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) +
               dfs(grid, i, j + 1) + 1;
    }
};

// 统计子岛屿
class Solution
{
public:
    int countSubIslands(vector<vector<int>> &grid1,
                        vector<vector<int>> &grid2)
    {
        int m = grid1.size(), n = grid1[0].size();
        int result = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 如果岛屿 B 中存在一片陆地，在岛屿 A
                // 的对应位置是海水，那么岛屿 B 就不是岛屿 A 的子岛。
                if (grid1[i][j] == 0 && grid2[i][j] == 1)
                {
                    // 不是子岛就阉掉
                    dfs(grid2, i, j);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1)
                {
                    // 记录岛屿数量
                    result++;
                    // 淹了
                    dfs(grid2, i, j);
                }
            }
        }
        return result;
    }

    // 从 (i, j) 开始，将与之相邻的陆地都变成海水
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n)
        {
            return;
        }
        if (grid[i][j] == 0)
        {
            return;
        }

        // 淹
        grid[i][j] = 0;
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
};