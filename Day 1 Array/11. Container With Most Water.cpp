// Problem Link :- https://leetcode.com/problems/container-with-most-water/

// Solved by Two Pointer Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int left = 0, right = n - 1, maxArea = 0;

        while (left <= right)
        {
            int area = (right - left) * min(height[left], height[right]);
            maxArea = max(maxArea, area);

            (height[left] < height[right]) ? left++ : right--;
        }

        return maxArea;
    }
};