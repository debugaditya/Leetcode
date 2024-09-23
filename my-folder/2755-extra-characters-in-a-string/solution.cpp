class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n + 1, n);  // DP array, initialized to worst case (all characters are extra)
        dp[0] = 0;  // Base case: no extra characters if we start with an empty string

        // Convert dictionary to a set for faster lookup
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        // DP to fill in the minimum extra characters
        for (int i = 0; i < n; ++i) {
            // Start by assuming the next character is extra
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            
            // Try all possible substrings starting from position i
            for (int j = i; j < n; ++j) {
                string sub = s.substr(i, j - i + 1);
                if (dict.count(sub)) {
                    // If the substring is in the dictionary, no extra characters are added
                    dp[j + 1] = min(dp[j + 1], dp[i]);
                }
            }
        }

        // dp[n] will contain the minimum number of extra characters for the entire string
        return dp[n];
    }
};


