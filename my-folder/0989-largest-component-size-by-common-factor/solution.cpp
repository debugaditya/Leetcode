class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if(parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }

    void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        DisjointSet ds(maxVal + 1);

        // Connect each number to its prime factors
        for(int num : nums) {
            for(int factor = 2; factor * factor <= num; ++factor) {
                if(num % factor == 0) {
                    ds.unionBySize(num, factor);
                    ds.unionBySize(num, num / factor);
                }
            }
        }

        unordered_map<int, int> count;
        int maxSize = 0;
        for(int num : nums) {
            int root = ds.find(num);
            count[root]++;
            maxSize = max(maxSize, count[root]);
        }

        return maxSize;
    }
};

