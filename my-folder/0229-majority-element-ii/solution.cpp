class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>v;
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
            if(mp[it]==nums.size()/3+1) v.push_back(it);
        }
        return v;
    }
};
