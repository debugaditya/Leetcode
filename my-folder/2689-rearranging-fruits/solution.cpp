class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        unordered_map<int,int>mp1,mp2; long long ans=0;
        for(auto it:b1) mp1[it]++; for(auto it:b2) mp2[it]++; vector<int>extra;
        int globalMin = min(*min_element(b1.begin(), b1.end()), *min_element(b2.begin(), b2.end()));
        for (auto &[num, cnt1] : mp1) {
            int cnt2 = mp2[num];
            if ((cnt1 + cnt2) % 2) return -1;
            int diff = (cnt1 - cnt2) / 2;
            while (diff-- > 0) extra.push_back(num);
        }
        for (auto &[num, cnt2] : mp2) {
            int cnt1 = mp1[num];
            if ((cnt1 + cnt2) % 2) return -1;
            int diff = (cnt2 - cnt1) / 2;
            while (diff-- > 0) extra.push_back(num);
        }

        sort(extra.begin(), extra.end());
        int n = extra.size();
        for (int i = 0; i < n / 2; i++) {
            ans += min(extra[i], 2 * globalMin); // key trick
        }
        return ans;
    }
};
