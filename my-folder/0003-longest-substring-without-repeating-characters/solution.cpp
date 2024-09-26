class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> c; // Vector to store lengths of valid substrings
        int a = 0; // Right pointer
        int b = 0; // Left pointer
        map<char, int> mp; // Map to store the last index of each character

        while (a < s.size()) {
            if (mp.find(s[a]) == mp.end()) {
                // Character not seen before
                mp[s[a]] = a; // Add character to map with its index
                a++;
            } else {
                // Character is a duplicate
                c.push_back(a - b); // Record length of current valid substring
                b = max(b, mp[s[a]] + 1); // Move `b` to the right of the last occurrence of s[a]
                mp[s[a]] = a; // Update last occurrence index
                a++; // Move right pointer
            }
        }

        // Capture the length of the last valid substring
        c.push_back(a - b); // Ensure we capture the last substring if it’s valid

        // Find maximum length from vector `c`
        int max1 = 0; 
        for (int i = 0; i < c.size(); i++) {
            max1 = max(max1, c[i]); 
        }
        return max1; 
    }
};


