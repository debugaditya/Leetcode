class Solution {
public:
    long long f(vector<int>& coins, long long amount, long long idx, vector<vector<long long>>& dp) {
        if (amount == 0) return 1; // Base case: found a valid way
        if (amount < 0 || idx >= coins.size()) return 0; // Invalid path
        
        if (dp[idx][amount] != -1) return dp[idx][amount]; // Return cached result

        // Explore two choices: include the current coin or skip it
        long long include = f(coins, amount - coins[idx], idx, dp); // Include current coin
        long long exclude = f(coins, amount, idx + 1, dp);         // Skip to the next coin

        return dp[idx][amount] = include + exclude; // Cache the result
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<long long>> dp(coins.size(), vector<long long>(amount + 1, -1));
        return f(coins, amount, 0, dp); // Start with the first coin and full amount
    }
};

