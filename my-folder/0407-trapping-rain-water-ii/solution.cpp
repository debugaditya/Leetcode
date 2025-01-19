#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int rows = heightMap.size();
        int cols = heightMap[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        // Add all boundary cells to the priority queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int trappedWater = 0;

        // Process cells in the priority queue
        while (!minHeap.empty()) {
            auto [height, cell] = minHeap.top();
            minHeap.pop();
            int x = cell.first, y = cell.second;

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                // Check if the neighbor is within bounds and not visited
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    // Calculate trapped water
                    trappedWater += max(0, height - heightMap[nx][ny]);
                    // Push the neighbor cell into the heap with the updated height
                    minHeap.push({max(height, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }

        return trappedWater;
    }
};

