class Solution {
public:
    
    int f(int n,vector<int>&dp){
        if(n==1||n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int sum=0; 
        for(int i=0;i<n;i++) sum+=f(i,dp)*f(n-1-i,dp);
        return dp[n]=sum;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};
