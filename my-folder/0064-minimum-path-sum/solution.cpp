class Solution {
public:
    int f(vector<vector<int>>& grid,int row,int col,vector<vector<int>>&dp){
        if(row>=grid.size()||col>=grid[0].size()) return INT_MAX;
        if(row==grid.size()-1&&col==grid[0].size()-1) return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=min(f(grid,row,col+1,dp),f(grid,row+1,col,dp))+grid[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return f(grid,0,0,dp);
    }
};
