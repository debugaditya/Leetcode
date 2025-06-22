class Solution {
public:
    long long f(vector<int>& prices, int index, vector<long long>& dp) {
        int n = prices.size();
        if (index >= n) return 0;  // already escaped, no more cost

        if (dp[index] != -1) return dp[index];

        long long ans = LLONG_MAX;
        for (int i = index + 1; i <= min(n, 2 * index + 2); ++i) {
            ans = min(ans, f(prices, i, dp));
        }

        return dp[index] = ans + prices[index];
    }

    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<long long> dp(n, -1);
        return f(prices, 0, dp);
    }
};

