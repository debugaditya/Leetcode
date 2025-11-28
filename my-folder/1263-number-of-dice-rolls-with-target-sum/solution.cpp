class Solution {
public:
    int f(int n,int sum,int &k, int &target,vector<vector<int>>&dp){
        if(sum>target) return 0;
        if(n==0) return sum==target;
        if(dp[n][sum]!=-1) return dp[n][sum];
        long long ans=0; for(int i=1;i<=k;i++) ans=(ans+f(n-1,sum+i,k,target,dp))%1000000007;
        return dp[n][sum]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return f(n,0,k,target,dp);
    }
};
