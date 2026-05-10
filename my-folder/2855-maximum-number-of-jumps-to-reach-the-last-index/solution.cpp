class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int>dp(nums.size(),-1); dp.back()=0;
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=i+1;j<nums.size();j++) if(abs(nums[j]-nums[i])<=target) dp[i]=max(dp[i],dp[j]);
            if(dp[i]!=-1) dp[i]++;
        }
        return dp[0];
    }
};
