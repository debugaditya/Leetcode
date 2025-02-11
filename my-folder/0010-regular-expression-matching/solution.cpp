class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true; // Empty string matches empty pattern

        // Handle cases where pattern contains '*' that can eliminate preceding elements
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2]; // '*' removes preceding element
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    // Characters match or '.' matches any character
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // '*' can mean:
                    // 1. Ignore previous character (zero occurrences) → dp[i][j - 2]
                    // 2. Use previous character if it matches → dp[i - 1][j]
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i][j - 2]; // Ignore '*' and previous char
                    }
                }
            }
        }

        return dp[m][n];
    }
};

