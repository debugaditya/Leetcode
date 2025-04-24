class Solution {
public:
    int countCompleteSubarrays(vector<int>& n) {
        map<int,int>mp;
        for(auto it:n) mp[it]++;
        int distinct = mp.size();  // total distinct elements in full array
        int ans = 0;
        
        for (int i = 0; i < n.size(); ++i) {
            map<int,int> temp;
            int count = 0;
            for (int j = i; j < n.size(); ++j) {
                if (++temp[n[j]] == 1) count++;
                if (count == distinct) ans++;
            }
        }

        return ans;
    }
};

