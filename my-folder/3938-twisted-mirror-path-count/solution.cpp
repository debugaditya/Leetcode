class Solution {
public:
    int f(vector<vector<int>>& grid, int i,int j,int k, vector<vector<vector<int>>>&dp){
        if(i==grid.size()||j==grid[0].size()) return 0;
        if(i==grid.size()-1&&j==grid[0].size()-1) return 1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(grid[i][j]==0) return dp[i][j][k]=1LL*(f(grid,i+1,j,0,dp)+f(grid,i,j+1,1,dp))%1000000007;
        return dp[i][j][k]=f(grid,i+k,j+1-k,1-k,dp)%1000000007;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(2,-1)));
        return f(grid,0,0,0,dp)%1000000007;
    }
};
