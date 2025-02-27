class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index; // Maps value -> index
        vector<vector<int>> dp(n, vector<int>(n, 2)); // Default length of Fib-like sequence is 2
        int maxLen = 0;

        // Store each number's index in the map
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        // Iterate over all pairs (i, j) to build DP table
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int prev = arr[j] - arr[i]; // The required previous number
                
                // Check if 'prev' exists and its index is before 'i'
                if (index.find(prev) != index.end() && index[prev] < i) {
                    int k = index[prev]; // Found valid k
                    dp[i][j] = dp[k][i] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }

        return maxLen >= 3 ? maxLen : 0;
    }
};

