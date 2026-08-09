class Solution {
public:
    int f(int i,int turn,int m,vector<int>& piles,vector<vector<vector<int>>>&dp){
        if(i==piles.size()) return 0;
        if(dp[i][m][turn]!=-1) return dp[i][m][turn];
        int sum=0,ans=turn==0?0:INT_MAX;
        for(int j=i;j<min((int)piles.size(),i+2*m);j++){
            sum+=piles[j];
            if(turn==0) ans=max(ans,f(j+1,1-turn,max(m,j-i+1),piles,dp)+sum);
            else ans=min(ans,f(j+1,1-turn,max(m,j-i+1),piles,dp));
        }
        return dp[i][m][turn]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>>dp(piles.size(),vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        return f(0,0,1,piles,dp);
    }
};
