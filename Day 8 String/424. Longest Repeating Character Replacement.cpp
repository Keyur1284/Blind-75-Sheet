// Problem Link :- https://leetcode.com/problems/longest-repeating-character-replacement/

// Solved by Sliding Window + Two Pointer Approach
// Time Complexity :- O(26 * 2 * n)
// Space Complexity :- O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.length(), longest = 1;
        unordered_set<char> st(s.begin(), s.end());

        for (auto &ch : st)
        {
            int left = 0, right = 0, ops = k;

            while (right < n)
            {
                if (s[right] != ch)
                {
                    if (ops == 0)
                    {
                        while (left <= right && ops == 0)
                        {
                            if (k)
                                ops += (s[left] != ch);

                            left++;
                        }
                    }

                    if (ops)
                        ops--;
                }

                longest = max(longest, right - left + 1);
                right++;
            }
        }

        return longest;
    }
};



// Most Optimal Solution
// Time Complexity :- O(n)
// Space Complexity :- O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.length(), longest = 0, maxFreq = 0;
        unordered_map<char, int> freq;

        for (int left = 0, right = 0; right < n; right++)
        {
            freq[s[right]]++;
            maxFreq = max(freq[s[right]], maxFreq);

            int lettersToChange = (right - left + 1) - maxFreq;

            if (lettersToChange > k)
                freq[s[left++]]--;

            longest = max(right - left + 1, longest);
        }

        return longest;
    }
};