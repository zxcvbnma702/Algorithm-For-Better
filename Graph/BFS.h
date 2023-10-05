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
    std:cout<< start << " ";
    visited[start] = true;
    que.push(start);
    while (!que.empty())
    {
        int a = que.front();
        que.pop();
        for(EdgeNode* it = g->adjlist[a].first; it != nullptr; it = it->next)
        {
            int b = it->b;
            if(!visited[b])
            {
                std::cout<<b<<" ";
                visited[b] = true;
                que.push(b);
            }
        }
    }
}

void testBFS2()
{
     //每个一维的数组表示一条边的信息，依次是头结点、尾结点、权值
    vector<vector<int>> vec = { {1, 2, 0}, {1, 5, 0}, {2, 6, 0}, {6, 3, 0}, {6, 7, 0}, {3, 7, 0}, {3, 4, 0}, {4, 7, 0}, {4, 8, 0}, {7, 8, 0}};
    GraphEH* g = createEH(vec, 8);
    //打印邻接矩阵
    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        std::cout << i;
        EdgeNode* temp = g->adjlist[i].first;
        while (temp != nullptr)
        {
            std::cout << " -> " << temp->b;
            temp = temp->next;
        }std::cout << endl;
    }std::cout << endl;
 
    bool visited[maxsize];    //辅助函数，用于判断某顶点是否被访问过
 
    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    std::cout << "从顶点1出发得到的广度优先遍历：";
    BFS2(g, 1, visited);    //从顶点1开始进行广度优先遍历
    std::cout << endl;
 
    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    std::cout << "从顶点2出发得到的广度优先遍历：";
    BFS2(g, 2, visited);    //从顶点2开始进行广度优先遍历
    std::cout << endl;
 
    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        visited[i] = false;
    }
    std::cout << "从顶点3出发得到的广度优先遍历：";
    BFS2(g, 3, visited);    //从顶点3开始进行广度优先遍历
 
    return;
}