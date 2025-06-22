class Solution {
public:
    long long maxScore = 0;
    int changes = 0;

    void getMaxScore(int node, long long sum, vector<vector<int>>& tree, vector<int>& cost) {
        sum += cost[node];
        if (tree[node].empty()) {
            maxScore = max(1LL*maxScore, sum);
            return;
        }
        for (int child : tree[node]) {
            getMaxScore(child, sum, tree, cost);
        }
    }

    long long dfs(int node, vector<vector<int>>& tree, vector<int>& cost) {
        if (tree[node].empty()) return cost[node];

        vector<int> childScores;
        for (int child : tree[node]) {
            childScores.push_back(dfs(child, tree, cost));
        }

        int maxChildScore = *max_element(childScores.begin(), childScores.end());

        for (int i = 0; i < tree[node].size(); i++) {
            long long diff = 1LL*maxChildScore - 1LL*childScores[i];
            if (diff > 0) {
                cost[tree[node][i]] += diff;
                changes++;
            }
        }

        return 1LL*cost[node] + 1LL*maxChildScore;
    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> pilvordanq(n);

        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (!visited[v]) {
                    pilvordanq[u].push_back(v);
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        getMaxScore(0, 0, pilvordanq, cost);
        dfs(0, pilvordanq, cost);

        return changes;
    }
};

