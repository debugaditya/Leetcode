class Solution {
public:
    int f(vector<pair<int,int>>& mp,int idx,int m,int n,vector<vector<vector<int>>>&dp){
        if(idx==mp.size()||(m==0&&n==0)) return 0;
        if(dp[idx][m][n]!=-1) return dp[idx][m][n];
        int pick=0,notpick=0;
        if(m>=mp[idx].first&&n>=mp[idx].second) pick=1+f(mp,idx+1,m-mp[idx].first,n-mp[idx].second,dp);
        notpick=f(mp,idx+1,m,n,dp);
        return dp[idx][m][n]=max(pick,notpick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>mp(strs.size()); int i=0;
        vector<vector<vector<int>>>dp(mp.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        for(auto it:strs){
            int a=0,b=0;
            for(auto it1:it){
                if(it1=='1') b++;
                else a++;
            }
            mp[i++]={a,b};
        }
        return f(mp,0,m,n,dp);
    }
};
