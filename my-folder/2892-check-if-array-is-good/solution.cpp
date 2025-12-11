class Solution {
public:
    bool isGood(vector<int>& nums) {
        vector<int>mp(nums.size(),0);
        for(auto it:nums){
            if(it>=nums.size()) return false;
            mp[it]++;
        }
        for(int i=1;i<mp.size()-1;i++) if(mp[i]!=1) return false;
        return true;
    }
};
