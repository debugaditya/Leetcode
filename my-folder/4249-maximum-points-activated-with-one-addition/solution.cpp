class Solution {
public:
    int f(int i, vector<vector<int>>& points, vector<int>& vis, 
          unordered_map<int, vector<int>>& row, unordered_map<int, vector<int>>& col,
          unordered_set<int>& visX, unordered_set<int>& visY) {
        
        vis[i] = 1;
        int ans = 1;
        int x = points[i][0], y = points[i][1];

        // Only traverse this X coordinate if we haven't already processed it
        if (visX.find(x) == visX.end()) {
            visX.insert(x);
            for (int j : row[x]) {
                if (vis[j] == 0) {
                    ans += f(j, points, vis, row, col, visX, visY);
                }
            }
        }

        // Only traverse this Y coordinate if we haven't already processed it
        if (visY.find(y) == visY.end()) {
            visY.insert(y);
            for (int j : col[y]) {
                if (vis[j] == 0) {
                    ans += f(j, points, vis, row, col, visX, visY);
                }
            }
        }

        return ans;
    }

    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n + 1;

        vector<int> vis(n, 0);
        unordered_map<int, vector<int>> row, col;
        unordered_set<int> visX, visY; // Tracks which coordinates we've fully checked

        // 1. Group points by their X and Y coordinates to eliminate redundant checking
        for (int i = 0; i < n; i++) {
            row[points[i][0]].push_back(i);
            col[points[i][1]].push_back(i);
        }

        int maxi = 0, sec_maxi = 0;

        // 2. Compute component sizes (The 'if' statement acts as our memoization)
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                int cur = f(i, points, vis, row, col, visX, visY);
                
                // Track the two largest components
                if (cur >= maxi) {
                    sec_maxi = maxi;
                    maxi = cur;
                } else if (cur > sec_maxi) {
                    sec_maxi = cur;
                }
            }
        }

        // 3. We can always connect the two largest distinct components with 1 added point
        return min(n + 1, maxi + sec_maxi + 1);
    }
};
