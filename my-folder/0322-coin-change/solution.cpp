class Solution {
public:
    long long f(vector<int>& coins, long long amount,long long sum,vector<long long>&dp){
        if(sum==amount) return 0;
        if(sum>amount) return LLONG_MAX;
        if(dp[sum]!=-1) return dp[sum];
        long long mini=LLONG_MAX;
        for(auto it:coins){
            long long res=f(coins,amount,sum+it,dp);
            if(res!=LLONG_MAX) mini=min(mini,res+1);
        }
        return dp[sum]=mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<long long>dp(amount+1,-1);
        long long ans=f(coins,amount,0,dp);
        if(ans==LLONG_MAX) return -1;
        return ans;
    }
};
