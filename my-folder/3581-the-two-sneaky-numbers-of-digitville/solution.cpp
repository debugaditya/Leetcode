class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>mp(nums.size(),0),ans;
        for(auto it:nums){
            mp[it]++;
            if(mp[it]==2) ans.push_back(it);
        }
        return ans;
    }
};
