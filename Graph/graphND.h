#pragma once
#include <iostream>
using namespace std;

#define maxsize 100
#define inf 999999
// 邻接矩阵
struct Graph
{
    char node[maxsize];         // 顶点表, 记录顶点名字
    int edge[maxsize][maxsize]; // 邻接矩阵
    int nodeNum, edgeNum;       // 顶点数, 边数
};

/*  vector<vector<int>> vec = {
    {1, 2, 5}, {2, 3, 4}, {3, 1, 8},
    {3, 6, 9}, {4, 3, 5}, {4, 6, 6},
    {5, 4, 5}, {6, 1, 3}, {6, 5, 1} };
每个一维的数组表示一条边的信息，依次是头结点、尾结点、权值 */

Graph *create(vector<vector<int>> &vec, int nodeNum)
{
    Graph *g = new Graph;
    g->nodeNum = nodeNum;

    for (int i = 0; i < maxsize; i++)
    {
        for (int j = 0; j < maxsize; j++)
        {
            g->edge[i][j] = 0; // 对角线, 自己指自己
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        // 一条a<->b，权值为w的边
        int a = vec[i][0];
        int b = vec[i][1];
        int w = vec[i][2];
        g->edge[a][b] = w;
        g->edge[b][a] = w;
        g->edgeNum++;
    }
    return g;
}

int testCreate()
{
    // 每个一维的数组表示一条边的信息，依次是头结点、尾结点、权值
    vector<vector<int>> vec = {{1, 2, 5}, {2, 3, 4}, {3, 1, 8}, {3, 6, 9}, {4, 3, 5}, {4, 6, 6}, {5, 4, 5}, {6, 1, 3}, {6, 5, 1}};
    Graph *g = create(vec, 6);
    // 打印邻接矩阵
    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        for (int j = 1; j < g->nodeNum + 1; j++)
        {
            cout << g->edge[i][j];
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}

// 邻接表
struct EdgeNode // 边表节点
{
    int b; // 节点序号
    int w; // 节点权值
    EdgeNode *next = nullptr;
};

struct HeadNode
{
    char data; // 节点信息
    EdgeNode *first = nullptr;
};

struct GraphEH
{
    HeadNode adjlist[maxsize];
    int nodeNum, edgeNum;
};

void insertEdge(HeadNode &hn, EdgeNode *en)
{
    en->next = hn.first;
    hn.first = en;
}

GraphEH *createEH(vector<vector<int>> &vec, int nodeNum)
{
    GraphEH *g = new GraphEH;
    g->nodeNum = nodeNum;

    for (int i = 0; i < vec.size(); i++)
    {
        // 一条a<->b，权值为w的边
        int a = vec[i][0];
        int b = vec[i][1];
        int w = vec[i][2];

        EdgeNode *node = new EdgeNode;
        node->b = b;
        node->w = w;

        insertEdge(g->adjlist[a], node);

        node = new EdgeNode;
        node->b = a;
        node->w = w;

        insertEdge(g->adjlist[b], node);
    }
    return g;
}

int testCreateEH()
{
    // 每个一维的数组表示一条边的信息，依次是头结点、尾结点、权值
    vector<vector<int>> vec = {{1, 2, 5}, {2, 3, 4}, {3, 1, 8}, {3, 6, 9}, {4, 3, 5}, {4, 6, 6}, {5, 4, 5}, {6, 1, 3}, {6, 5, 1}};
    GraphEH *g = createEH(vec, 6);
    // 打印邻接表
    for (int i = 1; i < g->nodeNum + 1; i++)
    {
        cout << i;
        EdgeNode *temp = g->adjlist[i].first;
        while (temp != nullptr)
        {
            cout << " -> " << temp->b << "," << temp->w;
            temp = temp->next;
        }
        cout << endl;
    }
    return 0;
}