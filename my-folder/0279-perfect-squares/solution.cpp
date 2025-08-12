class Solution {
public:
    int f(int index,int n,vector<vector<int>>&dp){
        if(n==0) return 0;
        if(n<0||index==dp.size()) return INT_MAX;
        if(dp[index][n]!=-1) return dp[index][n];
        int pick=f(index,n-index*index,dp); if(pick!=INT_MAX) pick++;
        int notpick=f(index+1,n,dp);
        return dp[index][n]=min(pick,notpick);
    }
    int numSquares(int n) {
        int maxBase = 1;
        while (pow(maxBase, 2) <= n) maxBase++; 
        vector<vector<int>>dp(maxBase+1,vector<int>(n+1,-1));
        return f(1,n,dp);
    }
};
