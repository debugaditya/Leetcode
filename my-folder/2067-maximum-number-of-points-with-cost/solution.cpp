class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> prev(points[0].begin(), points[0].end());

        for (int r = 1; r < m; r++) {
            vector<long long> leftMax(n), rightMax(n), curr(n);

            leftMax[0] = prev[0];
            for (int j = 1; j < n; j++)
                leftMax[j] = max(leftMax[j - 1] - 1, prev[j]);

            rightMax[n - 1] = prev[n - 1];
            for (int j = n - 2; j >= 0; j--)
                rightMax[j] = max(rightMax[j + 1] - 1, prev[j]);

            for (int j = 0; j < n; j++)
                curr[j] = points[r][j] + max(leftMax[j], rightMax[j]);

            prev = move(curr);
        }

        return *max_element(prev.begin(), prev.end());
    }
};

