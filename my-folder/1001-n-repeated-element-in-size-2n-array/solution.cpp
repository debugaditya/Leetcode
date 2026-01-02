class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<bool>mp(10001,false);
        for(auto it:nums) {if(mp[it]) return it; mp[it]=true;}
        return 0;
    }
};
