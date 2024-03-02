#pragma once

#include "graphND.h"
#include <queue>

// 邻接矩阵实现
void BFS1(Graph *g, int start, bool visited[])
{
    queue<int> que;
    std::cout << start << " ";
    visited[start] = true;
    que.push(start);

    while (!que.empty())
    {
        int a = que.front();
        que.pop();
        for (int b = 1; b < g->nodeNum + 1; b++)
        {
            if (g->edge[a][b] != 0 && !visited[b])
            {
                std::cout << b << " ";
                visited[b] = true;
                que.push(b);
            }
        }
    }
}

void testBFS1()
{
    vector<vector<int>> vec = {{1, 2, 1}, {1, 5, 1}, {2, 6, 1}, {6, 3, 1}, {6, 7, 1}, {3, 7, 1}, {3, 4, 1}, {4, 7, 1}, {4, 8, 1}, {7, 8, 1}};
    Graph *g = create(vec, 8); // 构造图

    bool visited[maxsize]; // 辅助函数，用于判断某顶点是否被访问过

    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    cout << "从顶点1出发得到的广度优先遍历：";
    BFS1(g, 1, visited); // 从顶点1开始进行广度优先遍历
    cout << endl;

    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    cout << "从顶点2出发得到的广度优先遍历：";
    BFS1(g, 2, visited); // 从顶点2开始进行广度优先遍历
    cout << endl;

    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    cout << "从顶点3出发得到的广度优先遍历：";
    BFS1(g, 3, visited); // 从顶点3开始进行广度优先遍历
    return;
}

// 邻接表实现
void BFS2(GraphEH *g, int start, bool visited[])
{
    queue<int> que;
std:
    cout << start << " ";
    visited[start] = true;
    que.push(start);
    while (!que.empty())
    {
        int a = que.front();
        que.pop();
        for (EdgeNode *it = g->adjlist[a].first; it != nullptr; it = it->next)
        {
            int b = it->b;
            if (!visited[b])
            {
                std::cout << b << " ";
                visited[b] = true;
                que.push(b);
            }
        }
    }
}

void testBFS2()
{
    // 每个一维的数组表示一条边的信息，依次是头结点、尾结点、权值
    vector<vector<int>> vec = {{1, 2, 0}, {1, 5, 0}, {2, 6, 0}, {6, 3, 0}, {6, 7, 0}, {3, 7, 0}, {3, 4, 0}, {4, 7, 0}, {4, 8, 0}, {7, 8, 0}};
    GraphEH *g = createEH(vec, 8);
    // 打印邻接矩阵
    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        std::cout << i;
        EdgeNode *temp = g->adjlist[i].first;
        while (temp != nullptr)
        {
            std::cout << " -> " << temp->b;
            temp = temp->next;
        }
        std::cout << endl;
    }
    std::cout << endl;

    bool visited[maxsize]; // 辅助函数，用于判断某顶点是否被访问过

    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    std::cout << "从顶点1出发得到的广度优先遍历：";
    BFS2(g, 1, visited); // 从顶点1开始进行广度优先遍历
    std::cout << endl;

    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    std::cout << "从顶点2出发得到的广度优先遍历：";
    BFS2(g, 2, visited); // 从顶点2开始进行广度优先遍历
    std::cout << endl;

    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    std::cout << "从顶点3出发得到的广度优先遍历：";
    BFS2(g, 3, visited); // 从顶点3开始进行广度优先遍历

    return;
}

// 腐烂的橘子
class Solution
{
public:
    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    // 广度优先搜索
    int orangesRotting(vector<vector<int>> &grid)
    {
        int result = 0;
        int fresh = 0;
        // 橘子坐标是二维的, 使用pair<>
        queue<pair<int, int>> queue;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
                else if (grid[i][j] == 2)
                {
                    // 将腐烂的橘子入队
                    queue.push({i, j});
                }
            }
        }

        while (!queue.empty())
        {
            int size = queue.size();
            // 记录排空一次队列是否有橘子腐烂
            bool hasRotton = false;
            for (int i = 0; i < size; i++)
            {
                // 取出腐烂的橘子
                auto [x, y] = queue.front();
                queue.pop();

                // 向四个方向腐烂
                for (auto d : dirs)
                {
                    int nx = x + d.first;
                    int ny = y + d.second;

                    // 边界条件
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (grid[nx][ny] == 2 || grid[nx][ny] == 0)
                        continue;

                    // 腐烂新鲜的橘子
                    grid[nx][ny] = 2;
                    // 将腐烂的橘子加入队列
                    queue.push({nx, ny});
                    fresh--;
                    hasRotton = true;
                }
            }
            // 排空一次队列 ,腐烂时间+1
            if (hasRotton)
                result++;
        }

        // 有橘子腐烂不到
        if (fresh)
        {
            return -1;
        }

        return result;
    }
};