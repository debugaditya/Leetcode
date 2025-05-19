class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> adj;
    vector<vector<int>> parent;
    vector<int> depth;
    vector<long long> dist_root; // Use long long to avoid overflow

    void dfs(int node, int par, int d, long long dist) {
        parent[node][0] = par;
        depth[node] = d;
        dist_root[node] = dist;

        for (auto &[nxt, w] : adj[node]) {
            if (nxt != par) {
                dfs(nxt, node, d + 1, dist + w);
            }
        }
    }

    void buildLCA() {
        int LOG = 20; // ~log2(10^5)
        parent.assign(n, vector<int>(LOG, -1));
        depth.assign(n, 0);
        dist_root.assign(n, 0);

        dfs(0, -1, 0, 0);

        for (int k = 1; k < LOG; k++) {
            for (int v = 0; v < n; v++) {
                if (parent[v][k-1] != -1)
                    parent[v][k] = parent[parent[v][k-1]][k-1];
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int LOG = 20;
        for (int k = LOG-1; k >= 0; k--) {
            if (parent[u][k] != -1 && depth[parent[u][k]] >= depth[v]) {
                u = parent[u][k];
            }
        }
        if (u == v) return u;

        for (int k = LOG-1; k >= 0; k--) {
            if (parent[u][k] != -1 && parent[u][k] != parent[v][k]) {
                u = parent[u][k];
                v = parent[v][k];
            }
        }
        return parent[u][0];
    }

    long long dist(int u, int v) {
        int a = lca(u, v);
        return dist_root[u] + dist_root[v] - 2 * dist_root[a];
    }

    vector<int> minimumWeight(vector<vector<int>>& e, vector<vector<int>>& q) {
        n = e.size() + 1;
        adj.assign(n, vector<pair<int,int>>());

        for (auto &edge : e) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        buildLCA();

        vector<int> ans;
        for (auto &query : q) {
            int src1 = query[0], src2 = query[1], dest = query[2];
            long long d12 = dist(src1, src2);
            long long d1d = dist(src1, dest);
            long long d2d = dist(src2, dest);

            ans.push_back((d12 + d1d + d2d) / 2);
        }
        return ans;
    }
};

