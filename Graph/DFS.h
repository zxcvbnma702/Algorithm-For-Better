#pragma once

#include "graphND.h"

void DFS1(Graph *g, int v, bool visited[])
{
    std::cout << v << " "; // 访问初始顶点v
    visited[v] = true;     // 将顶点v标记已访问
    for (int b = 1; b < g->nodeNum + 1; b++)
    {
        int a = v;
        if (g->edge[a][b] != 0) // 如果a-b这条边存在
        {
            if (!visited[b]) // 如果顶点b还未被访问过
            {
                DFS1(g, b, visited);
            }
        }
    }
}

void testDFS1()
{
    // 每个一维的数组表示一条边的信息，依次是头结点、尾结点、权值
    vector<vector<int>> vec = {{1, 2, 1}, {1, 5, 1}, {2, 6, 1}, {6, 3, 1}, {6, 7, 1}, {3, 7, 1}, {3, 4, 1}, {4, 7, 1}, {4, 8, 1}, {7, 8, 1}};
    Graph *g = create(vec, 8); // 构造图

    bool visited[maxsize]; // 辅助函数，用于判断某顶点是否被访问过

    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    std::cout << "从顶点1出发得到的深度优先遍历：";
    DFS1(g, 1, visited); // 从顶点1开始进行深度优先遍历
    std::cout << endl;

    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    std::cout << "从顶点2出发得到的深度优先遍历：";
    DFS1(g, 2, visited); // 从顶点2开始进行深度优先遍历
    std::cout << endl;

    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    std::cout << "从顶点3出发得到的深度优先遍历：";
    DFS1(g, 3, visited); // 从顶点3开始进行深度优先遍历
    return;
}

void DFS2(GraphEH *g, int start, bool visited[])
{
    std::cout << start << " ";
    visited[start] = true;
    int a = start;
    for (EdgeNode *it = g->adjlist[a].first; it != nullptr; it = it->next)
    {
        int b = it->b;
        if (!visited[b])
        {
            DFS2(g, b, visited);
        }
    }
}

void testDFS2()
{
    vector<vector<int>> vec = {{1, 2, 0}, {1, 5, 0}, {2, 6, 0}, {6, 3, 0}, {6, 7, 0}, {3, 7, 0}, {3, 4, 0}, {4, 7, 0}, {4, 8, 0}, {7, 8, 0}};
    GraphEH *g = createEH(vec, 8); // 构造图

    bool visited[maxsize]; // 辅助函数，用于判断某顶点是否被访问过

    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    std::cout << "从顶点1出发得到的深度优先遍历：";
    DFS2(g, 1, visited); // 从顶点1开始进行深度优先遍历
    std::cout << endl;

    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    std::cout << "从顶点2出发得到的深度优先遍历：";
    DFS2(g, 2, visited); // 从顶点2开始进行深度优先遍历
    std::cout << endl;

    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    std::cout << "从顶点3出发得到的深度优先遍历：";
    DFS2(g, 3, visited); // 从顶点3开始进行深度优先遍历
    return;
}

class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    void dfs(vector<vector<int>> &graph, int n)
    {
        // 终止条件
        if (n == graph.size() - 1)
        {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < graph[n].size(); i++)
        {
            // 把和n相邻的节点全都分叉出去
            path.push_back(graph[n][i]);
            dfs(graph, graph[n][i]); // 进入下一层递归
            path.pop_back();         // 回溯，撤销本节点
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        path.push_back(0);
        dfs(graph, 0);
        return result;
    }
};

int **ans; // 结果二维数组
int stk[15];
int stkSize;

void dfs(int x, int n, int **graph, int *graphColSize, int *returnSize, int **returnColumnSizes)
{
    if (x == n)
    {
        int *tmp = malloc(sizeof(int) * stkSize);
        memcpy(tmp, stk, sizeof(int) * stkSize);
        ans[*returnSize] = tmp;
        (*returnColumnSizes)[(*returnSize)++] = stkSize;
        return;
    }

    for (int i = 0; i < graphColSize[x]; i++)
    {
        int y = graph[x][i];
        stk[stkSize++] = y;
        dfs(y, n, graph, graphColSize, returnSize, returnColumnSizes);
        stkSize--;
    }
}
int **allPathsSourceTarget(int **graph, int graphSize, int *graphColSize, int *returnSize, int **returnColumnSizes)
{
    stkSize = 0;
    stk[stkSize++] = 0;
    ans = malloc(sizeof(int *) * 16384);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 16384);
    dfs(0, graphSize - 1, graph, graphColSize, returnSize, returnColumnSizes);
    return ans;
}