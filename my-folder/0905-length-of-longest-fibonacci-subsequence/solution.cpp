class Solution {
public:
    unordered_map<int, int> mp;

    int f(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];

        int next = arr[i] + arr[j];
        if (mp.count(next)) {
            int k = mp[next];
            dp[i][j] = 1 + f(arr, j, k, dp);
            return dp[i][j];
        }

        return dp[i][j] = 2; // Only i and j form the sequence if no valid k
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) mp[arr[i]] = i;

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                maxLen = max(maxLen, f(arr, i, j, dp));
            }
        }

        return maxLen >= 3 ? maxLen : 0;
    }
};

