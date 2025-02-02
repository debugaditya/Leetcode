class Solution {
public:
    vector<int> dp;
    vector<vector<int>> dp2;

    int minCutsHelper(string &s, int end) {
        if (end >= s.size()) return 0; // No cut needed for a single character
        if (dp[end] != -1) return dp[end]; // Return memoized result

        int mini = INT_MAX;
        for (int j = end; j <s.size(); j++) {
            if (dp2[end][j]==1) { // Use precomputed palindrome table
                int cuts = minCutsHelper(s, j + 1) + 1;
                mini = min(mini, cuts);
            }
        }

        return dp[end] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        dp.assign(n, -1); // Memoization array for min cuts
        dp2.assign(n, vector<int>(n, 0)); // Precompute palindrome table

        // **Step 1: Precompute palindromes**
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j <= 1 || dp2[j + 1][i - 1])) {
                    dp2[j][i] = 1;
                }
            }
        }

        // **Step 2: Compute minimum cuts using recursion + memoization**
        return minCutsHelper(s, 0)-1;
    }
};

