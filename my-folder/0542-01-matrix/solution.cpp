class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(), 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;  // Mark 0 cells as visited immediately
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();  // Pop first to maintain your structure
            
            ans[row][col] = steps;

            if (row + 1 < mat.size() && visited[row + 1][col] == 0) {
                q.push({{row + 1, col}, steps + 1});
                visited[row + 1][col] = 1;
            }
            if (row - 1 >= 0 && visited[row - 1][col] == 0) {
                q.push({{row - 1, col}, steps + 1});
                visited[row - 1][col] = 1;
            }
            if (col + 1 < mat[0].size() && visited[row][col + 1] == 0) {
                q.push({{row, col + 1}, steps + 1});
                visited[row][col + 1] = 1;
            }
            if (col - 1 >= 0 && visited[row][col - 1] == 0) {
                q.push({{row, col - 1}, steps + 1});
                visited[row][col - 1] = 1;
            }
        }
        return ans;
    }
};

