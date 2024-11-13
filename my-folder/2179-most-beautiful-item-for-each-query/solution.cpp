class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans;
        sort(items.begin(), items.end());
        
        // Precompute the maximum beauty for each item
        vector<int> prefix_max(items.size());
        prefix_max[0] = items[0][1];  // Initialize with the beauty of the first item
        for (int i = 1; i < items.size(); i++) {
            prefix_max[i] = max(prefix_max[i - 1], items[i][1]);
        }

        // For each query, use upper_bound to find the answer
        for (int i = 0; i < queries.size(); i++) {
            // Use upper_bound to find the first item where the first element is > queries[i]
            int k = upper_bound(items.begin(), items.end(), vector<int>{queries[i], INT_MAX}) - items.begin();
            ans.push_back(k > 0 ? prefix_max[k - 1] : 0);  // If k > 0, get the max beauty, else 0
        }

        return ans;
    }
};

