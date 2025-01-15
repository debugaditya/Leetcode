class Solution {
public:
    int f(vector<int>& nums,int index,vector<int>&dp){
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int l=f(nums,index+1,dp);
        int r=f(nums,index+2,dp)+nums[index];
        return dp[index]=max(l,r);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return f(nums,0,dp);
    }
};
