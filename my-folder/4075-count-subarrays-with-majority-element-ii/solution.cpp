class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> pref(n+1, 0);

        // Build prefix sum of +1/-1 transform
        for(int i = 0; i < n; i++){
            pref[i+1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        // Coordinate compress
        vector<long long> comp = pref;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());
        
        auto getIndex = [&](long long x){
            return lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;
        };

        int m = comp.size();
        vector<long long> BIT(m+1, 0);

        auto update = [&](int i){
            for(; i <= m; i += i & -i) BIT[i]++;
        };
        auto query = [&](int i){
            long long res = 0;
            for(; i > 0; i -= i & -i) res += BIT[i];
            return res;
        };

        long long ans = 0;

        // Count number of previous prefix < current prefix
        for(int i = 0; i <= n; i++){
            int idx = getIndex(pref[i]);

            // count all prefix < current → query(idx-1)
            ans += query(idx - 1);

            // insert current
            update(idx);
        }

        return ans;
    }
};

