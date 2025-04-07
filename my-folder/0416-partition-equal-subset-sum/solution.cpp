class Solution {
public:
    bool f(vector<int>& nums,int sum,int index,int t,vector<vector<int>>&dp){
        if(sum==t) return true;
        if(sum>t) return false;
        if(index>=nums.size()||sum>t) return false;
        if(dp[index][sum]!=-1) return dp[index][sum];
        return dp[index][sum]=f(nums,sum+nums[index],index+1,t,dp)||f(nums,sum,index+1,t,dp);
    }
    bool canPartition(vector<int>& nums) {
        int t= accumulate(nums.begin(),nums.end(),0);
        if(t%2!=0) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(t / 2 + 1, -1));
        return f(nums,0,0,t/2,dp);
    }
};
