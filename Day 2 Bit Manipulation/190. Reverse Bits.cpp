// Problem Link :- https://leetcode.com/problems/reverse-bits/

// Solved by Bit Manipulation
// Time Complexity :- O(32)
// Space Complexity :- O(1)

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t mask = (1 << 31), revN = 0;

        for (int i = 0; i < 32; i++)
        {
            if (n & (1 << i))
                revN |= mask;

            mask >>= 1;
        }

        return revN;
    }
};



class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t revN = 0;

        for (int i = 0; i < 32; i++)
        {
            revN <<= 1;

            if (n & (1 << i))
                revN |= 1;
        }
        
        return revN;
    }
};