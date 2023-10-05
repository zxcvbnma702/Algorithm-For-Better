// 课程表-dfs
class Solution
{
public:
    vector<bool> onPath;
    vector<bool> visited;

    bool hasCycle = false;

    void traverse(vector<vector<int>> &graph, int start)
    {
        if (onPath[start])
        {
            hasCycle = true;
        }

        // 节点已经遍历过或者已经检测出环
        if (visited[start] || hasCycle)
        {
            return;
        }

        visited[start] = true;
        onPath[start] = true;

        for (int t : graph[start])
        {
            traverse(graph, t);
        }

        onPath[start] = false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);

        onPath = vector<bool>(numCourses);
        visited = vector<bool>(numCourses);

        for (auto &p : prerequisites)
        {
            // 先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1
            int from = p[1];
            int to = p[0];
            adj[from].push_back(to);
        }

        for (int i = 0; i < numCourses; i++)
        {
            traverse(adj, i);
        }

        return !hasCycle;
    }
};

// 课程表-bfs
class Solution
{
private:
    vector<vector<int>> edges;
    vector<int> indegree;

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        indegree.resize(numCourses);
        for (const auto &info : prerequisites)
        {
            // 先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1
            int from = info[1];
            int to = info[0];
            edges[from].push_back(to);
            indegree[to]++;
        }

        queue<int> que;
        // 将所有入度为0的节点入队
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
            }
        }

        int visited = 0;
        while (!que.empty())
        {
            ++visited;
            int u = que.front();
            que.pop();
            for (int v : edges[u])
            {
                // 将u指向的所有节点的入度减一
                indegree[v]--;
                // 将入度为0的节点入队
                if (indegree[v] == 0)
                {
                    que.push(v);
                }
            }
        }

        return visited == numCourses;
    }
};

// 课程表2-dfs
class Solution
{
public:
    vector<bool> onPath;
    vector<bool> visited;
    vector<int> postorder;
    bool hasCycle = false;

    void traverse(vector<vector<int>> &graph, int start)
    {
        if (onPath[start])
        {
            hasCycle = true;
        }

        // 节点已经遍历过或者已经检测出环
        if (visited[start] || hasCycle)
        {
            return;
        }

        visited[start] = true;
        onPath[start] = true;

        for (int t : graph[start])
        {
            traverse(graph, t);
        }

        postorder.push_back(start);
        onPath[start] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);

        onPath = vector<bool>(numCourses);
        visited = vector<bool>(numCourses);

        for (auto &p : prerequisites)
        {
            // 先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1
            int from = p[1];
            int to = p[0];
            adj[from].push_back(to);
        }

        for (int i = 0; i < numCourses; i++)
        {
            traverse(adj, i);
        }

        if (hasCycle)
        {
            return {};
        }

        reverse(postorder.begin(), postorder.end());

        return postorder;
    }
};

// 课程表2-bfs
class Solution
{
private:
    vector<vector<int>> edges;
    vector<int> indegree;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        indegree.resize(numCourses);
        vector<int> result;
        for (const auto &info : prerequisites)
        {
            // 先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1
            int from = info[1];
            int to = info[0];
            edges[from].push_back(to);
            indegree[to]++;
        }

        queue<int> que;
        // 将所有入度为0的节点入队
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
            }
        }

        int visited = 0;
        while (!que.empty())
        {
            ++visited;
            int u = que.front();
            que.pop();
            result.push_back(u);
            for (int v : edges[u])
            {
                // 将u指向的所有节点的入度减一
                indegree[v]--;
                // 将入度为0的节点入队
                if (indegree[v] == 0)
                {
                    que.push(v);
                }
            }
        }

        // 如果不存在环
        if (visited == numCourses)
        {
            return result;
        }

        return {};
    }
};