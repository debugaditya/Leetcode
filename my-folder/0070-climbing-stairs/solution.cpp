class Solution {
public:
    int f(int n,int sum, vector<int>&dp){
        if(dp[sum]!=-1) return dp[sum];
        if(sum>n) return 0;
        if(sum==n) return 1;
        return dp[sum]=f(n,sum+1,dp)+f(n,sum+2,dp);
    }
    int climbStairs(int n) {
        int sum=0;
        vector<int>dp(47,-1);
        return f(n,sum,dp);
    }
};
