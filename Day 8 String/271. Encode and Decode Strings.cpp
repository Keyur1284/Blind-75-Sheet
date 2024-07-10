// Problem Link :- https://neetcode.io/problems/string-encode-and-decode

// Sovled by adding length of string before the string itself
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    string encode(vector<string>& strs) {
        
        string encodedString = "";
        
        for (auto &str : strs)
        {
            int len = str.length();
            encodedString += to_string(len) + "#" + str;
        }
        
        return encodedString;
    }

    vector<string> decode(string s) {
        
        int n = s.length();
        vector<string> strs;
        
        int i = 0;
        while (i < n) 
        {
            int index = s.find('#', i);

            // int index = i;
            // while (s[index] != '#') {
            //     index++;
            // }

            int len = stoi(s.substr(i, index - i));
            string str = s.substr(index + 1, len);
            strs.emplace_back(str);
            i = index + len + 1;
        }
        
        return strs;
    }
};