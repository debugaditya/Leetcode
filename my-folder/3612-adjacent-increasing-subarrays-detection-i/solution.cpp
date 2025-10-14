class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<int>mp(nums.size(),0);
        int cnt=1; mp[0]=1;
        for(int i=1;i<mp.size();i++){
            if(nums[i]>nums[i-1]) cnt++;
            else cnt=1;
            mp[i]=cnt;
        }
        for(int i=2*k-1;i<nums.size();i++) if(mp[i]>=2*k||(mp[i-k]>=k&&mp[i]>=k)) return true;
        return false;
        
    }
};
