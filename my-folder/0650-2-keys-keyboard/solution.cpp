class Solution {
public:
    int f(int n,int &num,int move,int clip,vector<vector<vector<int>>>&dp){
        if(n==num) return 0;
        if(n<0||n>num) return INT_MAX;
        if(dp[n][move][clip]!=-1) return dp[n][move][clip];
        int c=INT_MAX,p=INT_MAX;
        if(move!=0) c=f(n,num,0,n,dp);
        if(clip>0) p=f(n+clip,num,1,clip,dp);
        return dp[n][move][clip]=min(c,p)==INT_MAX?INT_MAX:min(c,p)+1;
    }
    int minSteps(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(n+1,-1)));
        return f(1,n,1,0,dp);
    }
};
