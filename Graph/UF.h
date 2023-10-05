int n = 1005;                           // n根据题目中节点数量而定，一般比节点数量大一点就好
vector<int> father = vector<int>(n, 0); // C++里的一种数组结构

// 并查集初始化
void init()
{
    for (int i = 0; i < n; ++i)
    {
        father[i] = i;
    }
}
// 并查集里寻根的过程
int find(int u)
{
    return u == father[u] ? u : father[u] = find(father[u]); // 路径压缩
}

// 判断 u 和 v是否找到同一个根
bool isSame(int u, int v)
{
    u = find(u);
    v = find(v);
    return u == v;
}

// 将v->u 这条边加入并查集
void join(int u, int v)
{
    u = find(u); // 寻找u的根
    v = find(v); // 寻找v的根
    if (u == v)
        return; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
    father[v] = u;
}

// 寻找图中是否存在路径
class Solution
{
private:
    int n = 200005;                         // n根据题目中节点数量而定，一般比节点数量大一点就好
    vector<int> father = vector<int>(n, 0); // C++里的一种数组结构

    // 并查集初始化
    void init()
    {
        for (int i = 0; i < n; ++i)
        {
            father[i] = i;
        }
    }
    // 并查集里寻根的过程
    int find(int u)
    {
        return u == father[u] ? u : father[u] = find(father[u]); // 路径压缩
    }

    // 判断 u 和 v是否找到同一个根
    bool isSame(int u, int v)
    {
        u = find(u);
        v = find(v);
        return u == v;
    }

    // 将v->u 这条边加入并查集
    void join(int u, int v)
    {
        u = find(u); // 寻找u的根
        v = find(v); // 寻找v的根
        if (u == v)
            return; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
        father[v] = u;
    }

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        init();
        for (int i = 0; i < edges.size(); i++)
        {
            join(edges[i][0], edges[i][1]);
        }
        return isSame(source, destination);
    }
};

// 冗余链接1
class Solution
{
private:
    int n = 1005; // 节点数目
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

    bool isSame(int u, int v)
    {
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return;

        father[v] = u;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        init();
        for (int i = 0; i < edges.size(); i++)
        {
            if (isSame(edges[i][0], edges[i][1]))
                return edges[i];
            else
                (join(edges[i][0], edges[i][1]));
        }
        return {};
    }
};

// 冗余链接2
class Solution
{
private:
    static const int N = 1010; // 如题：二维数组大小的在3到1000范围内
    int father[N];
    int n; // 边的数量
    // 并查集初始化
    void init()
    {
        for (int i = 1; i <= n; ++i)
        {
            father[i] = i;
        }
    }
    // 并查集里寻根的过程
    int find(int u)
    {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    // 将v->u 这条边加入并查集
    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        father[v] = u;
    }
    // 判断 u 和 v是否找到同一个根
    bool same(int u, int v)
    {
        u = find(u);
        v = find(v);
        return u == v;
    }
    // 在有向图里找到删除的那条边，使其变成树
    vector<int> getRemoveEdge(const vector<vector<int>> &edges)
    {
        init(); // 初始化并查集
        for (int i = 0; i < n; i++)
        { // 遍历所有的边
            if (same(edges[i][0], edges[i][1]))
            { // 构成有向环了，就是要删除的边
                return edges[i];
            }
            join(edges[i][0], edges[i][1]);
        }
        return {};
    }
    // 删一条边之后判断是不是树
    bool isTreeAfterRemoveEdge(const vector<vector<int>> &edges, int deleteEdge)
    {
        init(); // 初始化并查集
        for (int i = 0; i < n; i++)
        {
            if (i == deleteEdge)
                continue;
            if (same(edges[i][0], edges[i][1]))
            { // 构成有向环了，一定不是树
                return false;
            }
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int inDegree[N] = {0}; // 记录节点入度
        n = edges.size();      // 边的数量
        for (int i = 0; i < n; i++)
        {
            inDegree[edges[i][1]]++; // 统计入度
        }

        vector<int> vec; // 记录入度为2的边（如果有的话就两条边）
        // 找入度为2的节点所对应的边，注意要倒序，因为优先返回最后出现在二维数组中的答案
        for (int i = n - 1; i >= 0; i--)
        {
            if (inDegree[edges[i][1]] == 2)
            {
                vec.push_back(i);
            }
        }

        // 处理图中情况1 和 情况2
        // 如果有入度为2的节点，那么一定是两条边里删一个，看删哪个可以构成树
        if (vec.size() > 0)
        {
            if (isTreeAfterRemoveEdge(edges, vec[0]))
            {
                return edges[vec[0]];
            }
            else
            {
                return edges[vec[1]];
            }
        }
        // 处理图中情况3
        // 明确没有入度为2的情况，那么一定有有向环，找到构成环的边返回就可以了
        return getRemoveEdge(edges);
    }
};

// 等式方程的可满足性
class Solution
{
private:
    int n = 26;                             // n根据题目中节点数量而定，一般比节点数量大一点就好
    vector<int> father = vector<int>(n, 0); // C++里的一种数组结构

    // 并查集初始化
    void init()
    {
        for (int i = 0; i < n; ++i)
        {
            father[i] = i; // 默认自己指向自己
        }
    }
    // 并查集里寻根的过程
    int find(int u)
    {
        return u == father[u] ? u : father[u] = find(father[u]); // 路径压缩
    }

    // 判断 u 和 v是否找到同一个根
    bool isSame(int u, int v)
    {
        u = find(u);
        v = find(v);

        return u == v;
    }

    // 将v->u 这条边加入并查集
    void join(int u, int v)
    {
        u = find(u); // 寻找u的根
        v = find(v); // 寻找v的根
        if (u == v)
            return; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
        father[v] = u;
    }

public:
    bool equationsPossible(vector<string> &equations)
    {
        init();
        // 把联通的等式形成图
        for (string q : equations)
        {
            if (q[1] == '=')
            {
                int index1 = q[0] - 'a';
                int index3 = q[3] - 'a';
                join(index1, index3);
            }
        }

        for (string q : equations)
        {
            if (q[1] == '!')
            {
                int index1 = q[0] - 'a';
                int index3 = q[3] - 'a';
                if (isSame(index1, index3))
                {
                    return false;
                }
            }
        }

        return true;
    }
};