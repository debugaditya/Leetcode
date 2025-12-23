class Solution {
public:
    long long f(int i,int sign,vector<int>& nums,vector<vector<long long>>&dp){
        if(i==nums.size()) return 0;
        if(dp[i][sign]!=-1) return dp[i][sign];
        long long pick=(sign==0?nums[i]:-nums[i]),notpick=f(i+1,sign,nums,dp);
        pick+=f(i+1,1-sign,nums,dp);
        return dp[i][sign]=max(pick,notpick);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>>dp(nums.size(),vector<long long>(2,-1));
        return f(0,0,nums,dp);
    }
};
