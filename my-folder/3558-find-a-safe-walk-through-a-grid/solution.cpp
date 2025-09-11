class Solution {
public:
    bool f(vector<vector<int>>& grid,int i,int j,int h,vector<vector<bool>>& vis,vector<vector<vector<int>>>&dp){
        if(i==grid.size()||j==grid[0].size()||i==-1||j==-1||vis[i][j]) return false;
        if(dp[i][j][h]!=-1) return (bool)dp[i][j][h];
        h-=grid[i][j]; if(h==0) return false;
        if(i==grid.size()-1&&j==grid[0].size()-1) return h>0;
        vis[i][j]=true; 
        bool ans=f(grid,i-1,j,h,vis,dp)||f(grid,i,j-1,h,vis,dp)||f(grid,i,j+1,h,vis,dp)||f(grid,i+1,j,h,vis,dp);
        vis[i][j]=false;
        h+=grid[i][j]; 
        return dp[i][j][h]=ans;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(health+1,-1)));
        return f(grid,0,0,health,vis,dp);
    }
};
