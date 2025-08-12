class Solution {
public:
    const int MOD=1000000007;
    int f(int index,long long n,int x,vector<vector<int>>&dp){
        if(n==0) return 1;
        if(n<0||index>=dp.size()) return 0;
        if(dp[index][n]!=-1) return dp[index][n];
        int pick=f(index+1,n-pow(index,x),x,dp);
        int notpick=f(index+1,n,x,dp);
        return dp[index][n]=(pick+notpick)%MOD;
    }
    int numberOfWays(int n, int x) {
        int maxBase = 1;
        while (pow(maxBase, x) <= n) maxBase++; 
        vector<vector<int>>dp(maxBase+1,vector<int>(n+1,-1));
        return f(1,n,x,dp);
    }
};
