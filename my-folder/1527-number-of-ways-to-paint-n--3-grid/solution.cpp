class Solution {
public:
    const int MOD=1000000007;
    long long f(int n,int mode,vector<vector<int>>&dp){
        if(n==0) return 1;
        if(dp[n][mode]!=-1) return dp[n][mode];
        if(mode==0) return dp[n][mode]=(2*f(n-1,1,dp)+3*f(n-1,0,dp))%MOD;
        return dp[n][mode]=(2*f(n-1,1,dp)+2*f(n-1,0,dp))%MOD;
    }
    int numOfWays(int n) {
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return 6*(f(n-1,0,dp)+f(n-1,1,dp))%MOD;
    }
};
