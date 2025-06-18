class Solution {
public:
    int dfs(int n,int days, int k, vector<vector<int>>& s, vector<vector<int>>& t,vector<vector<int>>&dp){
        if(k==days) return 0;
        if(dp[n][days]!=-1) return dp[n][days];
        int ans=s[days][n]+dfs(n,days+1,k,s,t,dp);
        for(int i=0;i<t.size();i++) if(i!=n) ans=max(ans,t[n][i]+dfs(i,days+1,k,s,t,dp));
        return dp[n][days]=ans; 
    }
    int maxScore(int n, int k, vector<vector<int>>& s, vector<vector<int>>& t) {
        vector<vector<int>>dp(n,vector<int>(k,-1)); int maxi=0;
        for(int i=0;i<t.size();i++) maxi=max(dfs(i,0,k,s,t,dp),maxi);
        return maxi;
    }
};
