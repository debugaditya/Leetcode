class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) {
        parent.resize(n);
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if(parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu != pv)
            parent[pu] = pv;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DisjointSet ds(c + 1); // 1-based indexing
        unordered_map<int, set<int>> componentOnline;
        vector<bool> online(c + 1, true);
        vector<int> ans;

        // Step 1: Build initial connections
        for (auto& conn : connections) {
            ds.unionSet(conn[0], conn[1]);
        }

        // Step 2: Fill in componentOnline sets
        for (int i = 1; i <= c; ++i) {
            int root = ds.find(i);
            componentOnline[root].insert(i);
        }

        // Step 3: Process queries
        for (auto& q : queries) {
            int type = q[0], x = q[1];
            int root = ds.find(x);

            if (type == 1) {
                if (online[x]) {
                    ans.push_back(x);
                } else {
                    if (componentOnline[root].empty()) {
                        ans.push_back(-1);
                    } else {
                        ans.push_back(*componentOnline[root].begin());
                    }
                }
            } else {
                if (online[x]) {
                    online[x] = false;
                    componentOnline[root].erase(x);
                }
            }
        }

        return ans;
    }
};

