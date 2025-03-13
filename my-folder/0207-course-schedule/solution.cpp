class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> g(n);
        vector<int> in_degree(n, 0);
        
        // Build adjacency list and in-degree array
        for (auto it : p) {
            g[it[1]].push_back(it[0]);
            in_degree[it[0]]++;
        }

        queue<int> q;
        vector<int> visited(n, 0);

        // Start BFS from nodes with in-degree 0
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (auto it : g[node]) {
                if (--in_degree[it] == 0) {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }

        // If all courses are visited, return true
        return count == n;
    }
};

