class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        const int inf = INT_MAX / 2;

        // 使用"邻接矩阵"存储边权,g[i][j]表示从点i到点j的距离
        // 因为节点范围为[1,n],因此初始化数组大小为n + 1
        vector<vector<int>> g(n + 1, vector<int>(n + 1, inf));
        for (auto &t : times)
        {
            // 起点 终点 权值
            int start = t[0];
            int end = t[1];
            g[start][end] = t[2];
        }

        // 距离数组,记录所有点到源点的最短距离,dist[i]表示从源点到点i的最短距离
        vector<int> dist(n + 1, inf);

        // 由于从 k 开始，所以该点距离设为 0，也即源点
        dist[k] = 0;
        // 把第0个点置0,不然会影响最后在dist中取最大值
        dist[0] = 0;

        // 记录数组,记录该节点是否已经被遍历,used[i]表示节点i已经被遍历过了
        vector<bool> used(n + 1);

        Dijkstra(dist, used, n, g);

        // 找到距离最远的点
        int maxP = 0;
        for (int i = 1; i <= n; i++)
        {
            maxP = max(dist[i], maxP);
        }
        return maxP == inf ? -1 : maxP;
    }

    void Dijkstra(vector<int> &dist, vector<bool> used, int n, vector<vector<int>> &g)
    {
        for (int i = 1; i <= n; i++)
        {
            // 在还未确定最短路的点中，寻找距离最小的点
            // 第一次循环时,由于dist[k] = 0,小于其他节点(INF),因此x=y,标记为true,更新dist数组
            // 更新dist数组过程:
            // 比如源点为2,指向1,3,那么dist[1] = g[2][1],dist[3] = g[2][3],其他值如dist[4] = g[2][4] = INF

            // 第二次循环,找到在源点指向的节点中距离最小的点,作为x
            // 比如源点为1,指向2,3,4.那么dist[2],dist[3],dist[4]都有值,源点已遍历跳过,其他节点为INF
            // 找到dist[2],dist[3],dist[4]中最小的一个点作为x来遍历
            int x = -1;
            for (int y = 1; y <= n; y++)
            {
                // 如果点已经是最短路径上的点 跳过
                if (used[y])
                    continue;
                if (x == -1 || dist[y] < dist[x])
                {
                    x = y;
                }
            }

            // 将找到的最短路径赋为true
            used[x] = true;
            for (int y = 1; y <= n; y++)
            {
                dist[y] = min(dist[y], dist[x] + g[x][y]);
            }
        }
    }
};

class Solution
{
    int N = 110, M = 6010;
    // 邻接矩阵数组：w[a][b] = c 代表从 a 到 b 有权重为 c 的边
    int[][] w = new int[N][N];
    int INF = 0x3f3f3f3f;
    int n, k;
public
    int networkDelayTime(int[][] ts, int _n, int _k)
    {
        n = _n;
        k = _k;
        // 初始化邻接矩阵
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                w[i][j] = w[j][i] = i == j ? 0 : INF;
            }
        }
        // 存图
        for (int[] t : ts)
        {
            int u = t[0], v = t[1], c = t[2];
            w[u][v] = c;
        }
        // 最短路
        floyd();
        // 遍历答案
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = Math.max(ans, w[k][i]);
        }
        return ans >= INF / 2 ? -1 : ans;
    }
    void floyd()
    {
        // floyd 基本流程为三层循环：
        // 枚举中转点 - 枚举起点 - 枚举终点 - 松弛操作
        for (int p = 1; p <= n; p++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    w[i][j] = Math.min(w[i][j], w[i][p] + w[p][j]);
                }
            }
        }
    }
}

class Solution
{
    int N = 110, M = 6010;
    // 邻接矩阵数组：w[a][b] = c 代表从 a 到 b 有权重为 c 的边
    int[][] w = new int[N][N];
    // dist[x] = y 代表从「源点/起点」到 x 的最短距离为 y
    int[] dist = new int[N];
    // 记录哪些点已经被更新过
    boolean[] vis = new boolean[N];
    int INF = 0x3f3f3f3f;
    int n, k;
public
    int networkDelayTime(int[][] ts, int _n, int _k)
    {
        n = _n;
        k = _k;
        // 初始化邻接矩阵
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                w[i][j] = w[j][i] = i == j ? 0 : INF;
            }
        }
        // 存图
        for (int[] t : ts)
        {
            int u = t[0], v = t[1], c = t[2];
            w[u][v] = c;
        }
        // 最短路
        dijkstra();
        // 遍历答案
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = Math.max(ans, dist[i]);
        }
        return ans > INF / 2 ? -1 : ans;
    }
    void dijkstra()
    {
        // 起始先将所有的点标记为「未更新」和「距离为正无穷」
        Arrays.fill(vis, false);
        Arrays.fill(dist, INF);
        // 只有起点最短距离为 0
        dist[k] = 0;
        // 迭代 n 次
        for (int p = 1; p <= n; p++)
        {
            // 每次找到「最短距离最小」且「未被更新」的点 t
            int t = -1;
            for (int i = 1; i <= n; i++)
            {
                if (!vis[i] && (t == -1 || dist[i] < dist[t]))
                    t = i;
            }
            // 标记点 t 为已更新
            vis[t] = true;
            // 用点 t 的「最小距离」更新其他点
            for (int i = 1; i <= n; i++)
            {
                dist[i] = Math.min(dist[i], dist[t] + w[t][i]);
            }
        }
    }
}

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 2));
        for (auto &it : times)
            dp[it[0]][it[1]] = it[2];
        for (int i = 1; i <= n; i++)
            dp[i][i] = 0; // 自己到自己为0

        Floyd(dp, n);

        int ret = 0;
        for (int i = 1; i <= n; i++)
            ret = max(ret, dp[k][i]);
        return ret == INT_MAX / 2 ? -1 : ret;
    }

    void Floyd(vector<vector<int>> &dp, int n)
    {
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
};