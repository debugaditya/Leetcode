class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int>mp(201,0); vector<vector<int>>ans;
        for(auto it:nums){
            if(mp[it]>=ans.size()) ans.push_back({});
            ans[mp[it]].push_back(it);
            mp[it]++;
        }
        return ans;
    }
};
