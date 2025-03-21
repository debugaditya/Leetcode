#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;  // Start or End blocked
        
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
        vector<vector<int>> dist(n, vector<int>(n, -1));
        
        q.push({0, 0});
        dist[0][0] = 1;  // Start point distance is 1
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == n-1 && c == n-1) return dist[r][c];  // Reached bottom-right
            
            for (auto& d : directions) {
                int nr = r + d[0], nc = c + d[1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;  // Update distance
                    q.push({nr, nc});
                }
            }
        }
        
        return -1;  // No path found
    }
};


