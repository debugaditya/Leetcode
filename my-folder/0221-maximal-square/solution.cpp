class Solution {
public:
    int f(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& dp, int &maxSide) {
        if (i >= matrix.size() || j >= matrix[0].size()) return 0;
        if (matrix[i][j] == '0') return 0;
        if (dp[i][j] != 0) return dp[i][j];

        dp[i][j] = 1 + min({f(matrix, i + 1, j, dp, maxSide), 
                            f(matrix, i + 1, j + 1, dp, maxSide), 
                            f(matrix, i, j + 1, dp, maxSide)});
        
        maxSide = max(maxSide, dp[i][j]); // Track maximum square side
        return dp[i][j];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxSide = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                f(matrix, i, j, dp, maxSide);
            }
        }
        return maxSide * maxSide;
    }
};
