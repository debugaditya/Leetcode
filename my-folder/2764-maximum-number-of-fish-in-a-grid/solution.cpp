class Solution {
public:
    int f(vector<vector<int>>& grid,int i1,int i2,vector<vector<int>>&dp){
        if(i1<0||i2<0||i1>=grid.size()||i2>=grid[0].size()) return 0;
        if(grid[i1][i2]==0) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        int fish=grid[i1][i2];
        grid[i1][i2]=0;
        dp[i1][i2]=fish+f(grid,i1-1,i2,dp)+f(grid,i1,i2-1,dp)+f(grid,i1+1,i2,dp)+f(grid,i1,i2+1,dp);
        return dp[i1][i2];
    }
    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        int maxi=0;
        for(int i1=0;i1<grid.size();i1++){
            for(int i2=0;i2<grid[0].size();i2++){
                if(grid[i1][i2]!=0) maxi=max(f(grid,i1,i2,dp),maxi);
            }
        }
        return maxi;
    }
};
