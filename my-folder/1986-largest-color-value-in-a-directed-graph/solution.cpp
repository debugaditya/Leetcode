class Solution {
public:
    int ans = 0;

    void dfs(int node, vector<vector<int>>& adj, string &c, vector<vector<int>>& dp, vector<bool>& visited) {
        visited[node] = true;

        for (auto it : adj[node]) {
            if (!visited[it])
                dfs(it, adj, c, dp, visited);

            for (int i = 0; i < 26; ++i) {
                dp[node][i] = max(dp[node][i], dp[it][i]);
            }
        }

        dp[node][c[node] - 'a']++;
        ans = max(ans, dp[node][c[node] - 'a']);
    }

    int largestPathValue(string c, vector<vector<int>>& e) {
        int n = c.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for (auto it : e) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        if (topo.size() < n) return -1;

        vector<vector<int>> dp(n, vector<int>(26, 0));
        vector<bool> visited(n, false);

        for (int node : topo) {
            if (!visited[node])
                dfs(node, adj, c, dp, visited);
        }

        return ans;
    }
};


