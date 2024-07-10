// Problem Link :- https://leetcode.com/problems/palindrome-number/

// Solved by using string conversion of integer
// Time Complexity :- O(log10(n))
// Space Complexity :- O(log10(n))

class Solution {
public:
    bool isPalindrome(int x) {
        
        string s = to_string(x);
        string t = string(s.rbegin(), s.rend());

        return (s == t);
    }
};



// Solved by Reversing
// Time Complexity :- O(log10(n))
// Space Complexity :- O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0) 
            return false;
        
        long long rev = 0, temp = x;
        
        while (temp) 
        {
            int digit = temp % 10;
            rev = rev * 10 + digit;
            temp /= 10;
        }
        
        return (rev == x);
    }
};



// Solved by Reversing half of the number
// Time Complexity :- O(log10(n))
// Space Complexity :- O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int rev = 0;

        while (x > rev)
        {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }

        return ((x == rev) || (x == rev/10));
    }
};