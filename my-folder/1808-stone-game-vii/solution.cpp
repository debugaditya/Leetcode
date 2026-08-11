class Solution {
public:
    int f(int l,int r,int turn,vector<int>&stones,vector<vector<vector<int>>>&dp){
        if(l==r) return 0;
        if(dp[l][r][turn]!=-1) return dp[l][r][turn];
        int left=f(l+1,r,1-turn,stones,dp)+(turn?stones[l]-stones[r]:stones[r]-stones[l]);
        int right=f(l,r-1,1-turn,stones,dp)+(turn?(l>0?stones[l-1]:0)-stones[r-1]:stones[r-1]-(l>0?stones[l-1]:0));
        if(turn) return dp[l][r][turn]=min(left,right);
        return dp[l][r][turn]=max(left,right);
    }
    int stoneGameVII(vector<int>& stones) {
        vector<vector<vector<int>>>dp(stones.size(),vector<vector<int>>(stones.size(),vector<int>(2,-1)));
        for(int i=1;i<stones.size();i++) stones[i]+=stones[i-1];
        return f(0,stones.size()-1,0,stones,dp);
    }
};
