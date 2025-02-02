class Solution {
public:
    int f(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if (i >= matrix.size() || j >= matrix[0].size()) return 0;
        if (matrix[i][j] == '0') return 0;
        if (dp[i][j] != 0) return dp[i][j];

        // Find max width of '1's in the current row
        int width = 0;
        while (j + width < matrix[0].size() && matrix[i][j + width] == '1') {
            width++;
        }

        int min_width = width;
        int max_area = width; // Current row rectangle

        // Extend downwards, updating min width
        for (int k = i + 1; k < matrix.size(); k++) {
            if (matrix[k][j] == '0') break;

            int row_width = 0;
            while (j + row_width < matrix[0].size() && matrix[k][j + row_width] == '1') {
                row_width++;
            }

            min_width = min(min_width, row_width);
            max_area = max(max_area, min_width * (k - i + 1));
        }

        return dp[i][j] = max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxi = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                maxi = max(maxi, f(matrix, i, j, dp));
            }
        }

        return maxi;
    }
};

