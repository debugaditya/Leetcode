class Solution {
public:
    int f(int i,int turn,vector<int>&pre,vector<vector<int>>&dp){
        if(i==pre.size()-1) return turn?-pre[i]:pre[i];
        if(dp[i][turn]!=INT_MIN) return dp[i][turn];
        int pick=f(i+1,1-turn,pre,dp)+(turn?-pre[i]:pre[i]);
        int notpick=f(i+1,turn,pre,dp);
        if(turn) return dp[i][turn]=min(pick,notpick);
        return dp[i][turn]=max(pick,notpick);
    }
    int stoneGameVIII(vector<int>& stones) {
        vector<vector<int>>dp(stones.size(),vector<int>(2,INT_MIN));
        for(int i=1;i<stones.size();i++) stones[i]=stones[i-1]+stones[i];
        return f(1,0,stones,dp);
    }
};
