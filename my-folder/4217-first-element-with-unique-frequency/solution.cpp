class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mp,mp2;
        for(auto it:nums) mp[it]++;
        for(auto it:mp) mp2[it.second]++;
        for(auto it:nums) if(mp2[mp[it]]==1) return it;
        return -1;
    }
};
