// Problem Link :- https://www.naukri.com/code360/problems/graph-valid-tree_1376618

// Solved by Union Find
// Time Complexity :- O(n)
// Space Complexity :- O(n)

bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    int comp = n;
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> findPar = [&](int node) -> int
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    };

    for (auto &it : edges)
    {
        int u = it[0], v = it[1];

        if (findPar(u) == findPar(v))
            return false;

        parent[findPar(u)] = findPar(v);
        comp--;
    }

    return comp == 1;
}

// Solved by checking cycle
// Time Complexity :- O(n)
// Space Complexity :- O(n)

bool checkCycle(int node, int par, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;

    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            if (checkCycle(it, node, adj, vis))
                return true;
        }

        else if (it != par)
            return true;
    }

    return false;
}

bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    vector<int> adj[n];
    vector<int> vis(n, 0);

    for (auto &it : edges)
    {
        adj[it[0]].emplace_back(it[1]);
        adj[it[1]].emplace_back(it[0]);
    }

    if (checkCycle(0, -1, adj, vis))
        return false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            return false;
    }

    return true;
}



// Solved by DFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

void DFS(int node, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;

    for (auto &it : adj[node])
    {
        if (!vis[it])
            DFS(it, adj, vis);
    }
}

bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    vector<int> adj[n];
    vector<int> vis(n, 0);

    for (auto &it : edges)
    {
        adj[it[0]].emplace_back(it[1]);
        adj[it[1]].emplace_back(it[0]);
    }

    DFS(0, adj, vis);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            return false;
    }

    return m == n - 1;
}