class Solution {
public:
    int f(int i,int t,vector<int>& s,vector<vector<int>>&dp){
        if(i==s.size()) return 0;
        if(dp[i][t]!=INT_MIN) return dp[i][t];
        int pick=(t+1)*s[i]+f(i+1,t+1,s,dp),notpick=f(i+1,t,s,dp);
        return dp[i][t]=max(pick,notpick);
    }
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end()); vector<vector<int>>dp(s.size(),vector<int>(s.size(),INT_MIN));
        return f(0,0,s,dp);
    }
};
