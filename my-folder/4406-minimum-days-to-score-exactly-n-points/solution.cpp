class Solution {
public:
    int f(int n,vector<int>&dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        long long sum=0; int i=0,mini=INT_MAX;
        while(sum<n){
            i++;
            sum+=i;
            if(n-sum>=0) mini=min(mini,i+f(n-sum,dp));
        }
        return dp[n]=1+mini;
    }
    int minDays(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp)-1;
    }
};
