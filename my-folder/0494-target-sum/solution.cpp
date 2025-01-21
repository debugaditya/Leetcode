class Solution {
public:
    int f(vector<int>& nums, int target, int sum, int i,int tsum, vector<vector<int>>&dp) {

        if (i == nums.size()) {
            if (sum == target) return 1;
            else return 0; 
        }
        if(i>nums.size()) return 0;
        if(dp[i][sum+tsum]!=-1) return dp[i][sum+tsum];
        return dp[i][sum+tsum]=f(nums,target,sum+nums[i],i+1,tsum,dp)+f(nums,target,sum-nums[i],i+1,tsum,dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int tsum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(nums.size()+1,vector<int>(2*tsum+1,-1));
        return f(nums,target,0,0,tsum,dp);
    }
};

