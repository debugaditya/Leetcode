class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& component) { 
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        component.push_back(node);

        while (!q.empty()) {
            int no = q.front();
            q.pop();
            for (auto it : adj[no]) {
                if (visited[it] == 0) {
                    visited[it] = 1;
                    q.push(it);
                    component.push_back(it);
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int cnt = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                vector<int> component;
                bfs(i, adj, visited, component);
                bool isComplete = true;
                int size = component.size();
                for (int node : component) {
                    if (adj[node].size() != size - 1) {  
                        isComplete = false;
                        break;
                    }
                }
                if (isComplete) cnt++;
            }
        }
        return cnt;
    }
};

