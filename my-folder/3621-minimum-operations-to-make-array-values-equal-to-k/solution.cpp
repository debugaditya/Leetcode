class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>mp(101,0);
        int ans=0;
        for(auto it:nums){
            if(it<k) return -1;
            mp[it]++;
            if(it>k&&mp[it]==1) ans++;
        }
        return ans;
    }
};
