// Problem Link :- https://leetcode.com/problems/sum-of-two-integers/

// Solved by Bit Manipulation
// Time Complexity :- O(1)
// Space Complexity :- O(1)

class Solution {
public:
    int getSum(int a, int b) {
        
        while(b)
        {
            int carry = (a & b);
            a ^= b;
            b = (carry << 1);
        }
        
        return a;
    }
};



class Solution {
public:
    int getSum(int a, int b) {
        
        if (b == 0)
            return a;

        int sum = (a ^ b);
        int carry = (a & b);
        return getSum(sum, (carry << 1));
    }
};