class Solution {
public:
    bool f(int n,int turn,vector<vector<int>>&dp){
        if(n==0) return turn;
        if(dp[n][turn]!=-1) return dp[n][turn];
        bool ans=turn?true:false;
        for(int i=1;i*i<=n;i++){
            if(turn){
                ans&=f(n-i*i,1-turn,dp);
                if(!ans) return dp[n][turn]=ans;
            }
            else{
                ans|=f(n-i*i,1-turn,dp);
                if(ans) return dp[n][turn]=ans;
            }
        }
        return dp[n][turn]=ans;
    }
    bool winnerSquareGame(int n) {
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return f(n,0,dp);
    }
};
