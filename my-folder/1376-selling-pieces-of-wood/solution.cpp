class Solution {
public:
    long long f(int m, int n, vector<vector<int>>& prices, vector<vector<long long>>& dp, vector<vector<long long>>& priceTable) {
        if (m == 0 || n == 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];
        
        // Start with the direct price if available
        long long maxi = priceTable[m][n];
        
        // Try all possible horizontal cuts (optimized to only check up to half)
        for (int i = 1; i <= m/2; i++) {
            maxi = max(maxi, f(i, n, prices, dp, priceTable) + f(m-i, n, prices, dp, priceTable));
        }
        
        // Try all possible vertical cuts (optimized to only check up to half)
        for (int j = 1; j <= n/2; j++) {
            maxi = max(maxi, f(m, j, prices, dp, priceTable) + f(m, n-j, prices, dp, priceTable));
        }
        
        return dp[m][n] = maxi;
    }

    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, -1));
        
        // Preprocess prices into a lookup table
        vector<vector<long long>> priceTable(m+1, vector<long long>(n+1, 0));
        for (const auto& p : prices) {
            if (p[0] <= m && p[1] <= n) {
                priceTable[p[0]][p[1]] = max(priceTable[p[0]][p[1]], (long long)p[2]);
            }
        }
        
        return f(m, n, prices, dp, priceTable);
    }
};
