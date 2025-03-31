class Solution {
public:
    int find(vector<int> &par, int i) {
        if (i != par[i])
            par[i] = find(par, par[i]);  // Path compression to prevent deep recursion
        return par[i];
    }

    void Union(vector<int> &par, vector<int> &size, int i, int j) {
        int par_i = find(par, i);
        int par_j = find(par, j);

        if (par_i == par_j) return;

        if (size[par_i] > size[par_j]) {
            par[par_j] = par_i;
            size[par_i] += size[par_j];  // Merge smaller into larger
        } else {
            par[par_i] = par_j;
            size[par_j] += size[par_i];  // Merge smaller into larger
        }
    }

    int removeStones(vector<vector<int>>& s) {
        int cnt = 0;
        int maxr = 0, maxc = 0;
        
        for (auto it : s) {
            maxr = max(maxr, it[0]);
            maxc = max(maxc, it[1]);
        }
        
        int total = maxr + maxc + 2; // Ensure safe DSU size
        vector<int> par(total), size(total, 1);
        
        for (int i = 0; i < total; i++) 
            par[i] = i;
        
        unordered_set<int> nodes;
        
        for (auto it : s) {
            int row = it[0];
            int col = it[1] + maxr + 1;
            Union(par, size, row, col);
            nodes.insert(row);
            nodes.insert(col);
        }
        
        for (int node : nodes) 
            if (find(par, node) == node) 
                cnt++; 

        return s.size() - cnt;
    }
};

