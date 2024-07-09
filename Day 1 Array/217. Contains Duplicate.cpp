// Problem Link :- https://leetcode.com/problems/contains-duplicate/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                return true;
        }
        
        return false;
    }
};



// Solved using unordered_set
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> vis;

        for (auto &it : nums)
        {
            if (vis.count(it))
                return true;

            vis.emplace(it);
        }

        return false;
    }
};