class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int ans = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();
            grid[i][j] = 2;
            
            if(i-1 >= 0 && visited[i-1][j] == 0 && grid[i-1][j] == 1) {
                q.push({{i-1, j}, t+1});
                visited[i-1][j] = 1;
            }
            if(i+1 < grid.size() && visited[i+1][j] == 0 && grid[i+1][j] == 1) {
                q.push({{i+1, j}, t+1});
                visited[i+1][j] = 1;
            }
            if(j+1 < grid[0].size() && visited[i][j+1] == 0 && grid[i][j+1] == 1) {
                q.push({{i, j+1}, t+1});
                visited[i][j+1] = 1;
            }
            if(j-1 >= 0 && visited[i][j-1] == 0 && grid[i][j-1] == 1) {
                q.push({{i, j-1}, t+1});
                visited[i][j-1] = 1;
            }
            ans = max(ans, t);
        }

        for(int p = 0; p < grid.size(); p++){
            for(int k = 0; k < grid[0].size(); k++){
                if(grid[p][k] == 1) return -1;
            }
        }
        return ans;
    }
};


