class Solution {
public:
    int f(vector<vector<int>>& grid, int i,int j,int k,vector<vector<vector<int>>>& dp){
        if(k<0||i==grid.size()||j==grid[0].size()) return -1;
        if(i==grid.size()-1&&j==grid[0].size()-1&&k-(grid[i][j]>0?1:0)>=0) return grid[i][j];
        if(dp[i][j][k]!=-2) return dp[i][j][k];
        int right=f(grid,i,j+1,k-(grid[i][j]>0?1:0),dp);
        int down=f(grid,i+1,j,k-(grid[i][j]>0?1:0),dp);
        int ans=max(right,down);
        if(ans>=0) ans+=grid[i][j];
        return dp[i][j][k]=ans;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k+1,-2)));
        return f(grid,0,0,k,dp);
    }
};
