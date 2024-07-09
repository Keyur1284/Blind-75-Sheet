// Problem Link :- https://leetcode.com/problems/jump-game/

// Solved by Memoization Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:

    int solve(int index, int &n, vector<int> &nums, vector<int> &dp)
    {
        if (index >= n - 1)
            return 1;

        if (dp[index] != -1)
            return dp[index];

        for (int curr = index + 1; curr <= index + nums[index]; curr++)
        {
            if (solve(curr, n, nums, dp))
                return dp[index] = 1;
        }

        return dp[index] = 0;
    }

    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, n, nums, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[n - 1] = 1;
        
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j <= i + nums[i] && j < n; j++)
            {
                if (dp[j])
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};



// Solved by Greedy Method
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    bool canJump(vector<int>& nums) {
        
        int n = nums.size(), maxIndex = 0;

        for (int i = 0; i < n; i++)
        {
            if (i > maxIndex)
                return false;

            maxIndex = max(i + nums[i], maxIndex);

            if (maxIndex >= n - 1)
                return true;
        }

        return false;
    }
};