class Solution {
public:
    long long f(int i,int j,int mod,int m,int n,vector<vector<int>>&w,vector<vector<vector<long long>>>&dp){
        if(i>m-1||j>n-1) return 1000000000000;
        if(i==m-1&&j==n-1) return 0;
        if(dp[i][j][mod]!=-1) return dp[i][j][mod];
        if(mod==0) return dp[i][j][mod]=w[i][j]+f(i,j,1-mod,m,n,w,dp);
        long long right=f(i,j+1,1-mod,m,n,w,dp)+(i+1)*(j+2);
        long long down=f(i+1,j,1-mod,m,n,w,dp)+(i+2)*(j+1);
        return dp[i][j][mod]=min(right,down);
    }
    long long minCost(int m, int n, vector<vector<int>>&w) {
        vector<vector<vector<long long>>>dp(m,vector<vector<long long>>(n,vector<long long>(2,-1)));
        return 1+f(0,0,1,m,n,w,dp);
    }
};
