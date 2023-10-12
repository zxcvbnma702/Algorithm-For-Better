// 最小生成树-prim
class Solution
{
public:
    int prim(vector<vector<int>> &points, int start)
    {
        // 图的节点数量
        int n = points.size();
        // 最小生成树长
        int res = 0;

        // 构建邻接矩阵
        vector<vector<int>> graph(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i][j] = graph[j][i] = dist;
            }
        }

        vector<int> lowcost(n, INT_MAX);
        vector<bool> marked(n);

        marked[start] = true;
        // 先将开始节点的临接边存下来
        for (int i = 0; i < n; i++)
        {
            if (i == start)
                continue;
            lowcost[i] = graph[i][start];
        }

        // 遍历剩下n-1个节点
        for (int i = 1; i < n; i++)
        {
            // 找出最短的邻边(替代优先队列)
            int minIdx = -1;
            int minVal = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (marked[j] == false && lowcost[j] < minVal)
                {
                    minVal = lowcost[j];
                    minIdx = j;
                }
            }

            // 将最近的节点加入标记数组
            marked[minIdx] = true;
            res += minVal;

            // 以最近的节点为中心,将其邻边加入优先队列
            for (int j = 0; j < n; j++)
            {
                if (marked[j] == false && graph[j][minIdx] < lowcost[j])
                {
                    lowcost[j] = graph[j][minIdx];
                }
            }
        }
        return res;
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        return prim(points, 0);
    }
};

// 最小生成树-kruskal
class Solution
{
public:
    int n = 1005;
    vector<int> father = vector<int>(n, 0);

    void init()
    {
        for (int i = 0; i < n; i++)
        {
            father[i] = i;
        }
    }

    int find(int u)
    {
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    // 判断根是否相同
    bool isSame(int u, int v)
    {
        u = find(u);
        v = find(v);
        return u == v;
    }

    bool join(int u, int v)
    {
        if (isSame(u, v))
        {
            return false;
        }

        father[v] = u;

        return true;
    }

    struct Edge
    {
        int start;
        int end;
        int len;
    };

    int kruskal(vector<vector<int>> &points)
    {
        // 最小生成树权值之和
        int res = 0;
        int num = 1;
        n = points.size();
        init();

        vector<Edge> edges;

        // 建立点-边式数据结构
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                Edge edge = {i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])};
                edges.emplace_back(edge);
            }
        }

        for (int i = 0; i < edges.size(); i++)
        {
        }
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) -> int
             { return a.len < b.len; });

        for (int i = 0; i < edges.size(); i++)
        {
            if (join(edges[i].start, edges[i].end))
            {
                res += edges[i].len;
                num++;

                if (num == n)
                {
                    return res;
                }
            }
        }

        return res;
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        return kruskal(points);
    }
};

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b, *b = tmp;
}

struct Edge
{
    int len, x, y;
};

int cmp(struct Edge *a, struct Edge *b)
{
    return a->len - b->len;
}

int find(int *f, int x)
{
    return f[x] == x ? x : (f[x] = find(f, f[x]));
}

int unionSet(int *f, int *rank, int x, int y)
{
    int fx = find(f, x), fy = find(f, y);
    if (fx == fy)
    {
        return false;
    }
    if (rank[fx] < rank[fy])
    {
        swap(&fx, &fy);
    }
    rank[fx] += rank[fy];
    f[fy] = fx;
    return true;
}

int minCostConnectPoints(int **points, int pointsSize, int *pointsColSize)
{
    int n = pointsSize;
    struct Edge edges[(n + 1) * n / 2];
    int edgesSize = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            edges[edgesSize].x = i;
            edges[edgesSize].y = j;
            edges[edgesSize++].len = fabs(points[i][0] - points[j][0]) + fabs(points[i][1] - points[j][1]);
        }
    }
    qsort(edges, edgesSize, sizeof(struct Edge), cmp);
    int f[n], rank[n];
    for (int i = 0; i < n; i++)
    {
        f[i] = i;
        rank[i] = 1;
    }
    int ret = 0, num = 1;
    for (int i = 0; i < edgesSize; i++)
    {
        if (unionSet(f, rank, edges[i].x, edges[i].y))
        {
            ret += edges[i].len;
            num++;
            if (num == n)
            {
                break;
            }
        }
    }
    return ret;
}