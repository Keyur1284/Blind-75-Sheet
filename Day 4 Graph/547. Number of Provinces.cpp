// Problem Link :- https://leetcode.com/problems/number-of-provinces/

// Solved by DFS
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    
    void DFS (int node, vector <int> adj[], vector <int> &vis)
    {
        vis[node] = 1;
        
        for (auto it : adj[node])
        {
            if (!vis[it])
                DFS(it, adj, vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int v = isConnected.size();
        
        vector <int> vis (v, 0);
        int count = 0;
        
        vector <int> adj[v];
        
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }    

                // Or we can also do this
                // if (isConnected[i][j])
                    // adj[i].emplace_back(j);
            }
        }
        
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                DFS(i, adj, vis);
                count++;
            }
        }
        
        return count;  
    }
};



class Solution {
public:
    
    void DFS (int node, vector<vector<int>>& isConnected, vector <int> &vis)
    {
        vis[node] = 1;
        
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!vis[i] && isConnected[node][i])
                DFS(i, isConnected, vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int v = isConnected.size();
        
        vector <int> vis (v, 0);
        int count = 0;
        
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                DFS(i, isConnected, vis);
                count++;
            }
        }
        
        return count;  
    }
};



// Solved using DSU
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class DSU {

private:
    
    vector<int> parent, rank, size;

public:

    DSU (int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.emplace_back(i);
            rank.emplace_back(0);
            size.emplace_back(1);
        }
    }

    int findPar (int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void UnionRank (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }

        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }

        else if (rank[u] == rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    void UnionSize (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }

        else if (rank[u] >= rank[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }    
};

class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        DSU dsu(n - 1);

        int count = n;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j] && dsu.findPar(i) != dsu.findPar(j))
                {
                    count--;
                    dsu.UnionRank(i, j);
                }
            }
        }

        return count;
    }
};


class DSU {

private:
    
    vector<int> parent, rank, size;

public:

    DSU (int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.emplace_back(i);
            rank.emplace_back(0);
            size.emplace_back(1);
        }
    }

    int findPar (int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void UnionRank (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }

        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }

        else if (rank[u] == rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    void UnionSize (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }

        else if (rank[u] >= rank[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }    
};

class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        DSU dsu(n - 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j])
                {
                    dsu.UnionRank(i, j);
                }
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (dsu.findPar(i) == i)
                count++;
        }

        return count;
    }
};