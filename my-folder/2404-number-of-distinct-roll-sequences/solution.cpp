class Solution {
public:
    int mod = 1e9 + 7;
    int dp[10005][7][7];

    int f(int idx, int prev, int prev2, int n) {
        if (idx == n) return 1;
        if (dp[idx][prev][prev2] != -1) return dp[idx][prev][prev2];
        
        int ans = 0;
        for (int i = 1; i <= 6; i++) {
            if (i == prev || i == prev2) continue;
            if ((i % 2 == 0) && (prev % 2 == 0) && prev != 0) continue;
            if ((i == 3 && prev == 6) || (i == 6 && prev == 3)) continue;
            ans = (ans + f(idx + 1, i, prev, n)) % mod;
        }

        return dp[idx][prev][prev2] = ans;
    }

    int distinctSequences(int n) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0, n);
    }
};

