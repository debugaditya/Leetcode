class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> mp(k, 0);  // frequency of product mods ending at previous index

        for (auto it : nums) {
            int prod = it % k;
            vector<long long> newMp(k, 0);

            // extend previous subarrays
            for (int q = 0; q < k; q++) {
                int new_mod = (q * prod) % k;
                newMp[new_mod] += mp[q];
            }

            // start new subarray with current element
            newMp[prod]++;

            // update answer and mp
            for (int q = 0; q < k; q++) {
                ans[q] += newMp[q];
                mp[q] = newMp[q];
            }
        }
        return ans;
    }
};

