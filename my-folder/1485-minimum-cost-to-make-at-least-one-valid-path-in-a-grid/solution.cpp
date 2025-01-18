class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Directions for {right, left, down, up}
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0;

        // Priority queue: {current cost, row, col}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0}); // Start at (0, 0) with cost 0

        while (!pq.empty()) {
            auto [currCost, row, col] = pq.top();
            pq.pop();

            // If we reach the destination, return the cost
            if (row == m - 1 && col == n - 1) return currCost;

            // Skip if a better cost has already been recorded
            if (currCost > cost[row][col]) continue;

            // Explore all 4 directions
            for (int d = 0; d < 4; ++d) {
                int newRow = row + directions[d].first;
                int newCol = col + directions[d].second;
                int extraCost = (d + 1 == grid[row][col]) ? 0 : 1; // Preferred direction is cost 0

                // Boundary check and cost update
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    int newCost = currCost + extraCost;
                    if (newCost < cost[newRow][newCol]) {
                        cost[newRow][newCol] = newCost;
                        pq.push({newCost, newRow, newCol});
                    }
                }
            }
        }

        return -1; // Shouldn't reach here for valid inputs
    }
};


