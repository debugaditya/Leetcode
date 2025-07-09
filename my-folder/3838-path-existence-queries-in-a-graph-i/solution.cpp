class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Create a vector of pairs (value, index) to sort while keeping track of original indices
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < n; i++) {
            indexedNums.emplace_back(nums[i], i);
        }
        
        // Sort based on the numeric values
        sort(indexedNums.begin(), indexedNums.end());
        
        DSU ds(n);
        
        // Group elements that are within maxDiff in the sorted array
        for (int i = 1; i < n; i++) {
            if (indexedNums[i].first - indexedNums[i-1].first <= maxDiff) {
                ds.unionSet(indexedNums[i-1].second, indexedNums[i].second);
            }
        }
        
        // Process queries
        vector<bool> ans;
        for (const auto& query : queries) {
            ans.push_back(ds.find(query[0]) == ds.find(query[1]));
        }
        
        return ans;
    }
};
