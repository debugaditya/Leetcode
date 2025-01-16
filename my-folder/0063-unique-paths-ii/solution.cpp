class Solution {
public:
    int f(vector<vector<int>>& obstacleGrid,int m,int n,int row,int col,vector<vector<int>>&dp){
        if (row==m-1&&col==n-1) return 1; 
        if (row>=m||col>=n) return 0;
        if(obstacleGrid[row][col]==1) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=f(obstacleGrid,m,n,row+1,col,dp)+f(obstacleGrid,m,n,row,col+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(obstacleGrid,m,n,0,0,dp);
    }
};
