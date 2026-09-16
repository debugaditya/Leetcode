class Solution {
public:
    const int mod=1e9+7;
    int f(int i,int cnt,vector<vector<int>>&dp){
        if(i==dp.size()||cnt==dp[0].size()) return cnt==dp[0].size();
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        long ans=0;
        ans+=f(i+1,cnt,dp); ans%=mod;
        ans+=f((cnt%2==0?i+1:i),cnt+1,dp); ans%=mod;
        return dp[i][cnt]=ans;
    }
    int numberOfSets(int n, int k) {
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
        return f(0,0,dp);
    }
};
