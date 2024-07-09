// Problem Link :- https://leetcode.com/problems/pacific-atlantic-water-flow/

// Solved by DFS
// Time Complexity :- O(n * m)
// Space Complexity :- O(n * m)

class Solution {
public:

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    bool isValid (int x, int y, int m, int n)
    {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    void DFS (int x, int y, int flag, int &m, int &n, vector<vector<vector<bool>>> &flow, vector<vector<int>>& heights)
    {
        flow[x][y][flag] = true;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i], newy = y + dy[i];

            if (isValid(newx, newy, m, n) && !flow[newx][newy][flag] && heights[newx][newy] >= heights[x][y])
                DFS (newx, newy, flag, m, n, flow, heights);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size(), n = heights[0].size();
        vector<vector<vector<bool>>> flow (m, vector<vector<bool>> (n, vector<bool> (2, false)));

        // Pacific Ocean -> 0,  Atlantic Ocean -> 1

        for (int row = 0; row < m; row++)
        {
            DFS (row, 0, 0, m, n, flow, heights);
            DFS (row, n - 1, 1, m, n, flow, heights);
        }

        for (int col = 0; col < n; col++)
        {
            DFS (0, col, 0, m, n, flow, heights);
            DFS (m - 1, col, 1, m, n, flow, heights);
        }

        vector<vector<int>> result;

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (flow[row][col][0] && flow[row][col][1])
                    result.push_back({row, col});
            }
        }

        return result;
    }
};