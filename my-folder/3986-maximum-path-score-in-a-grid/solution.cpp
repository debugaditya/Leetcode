class Solution {
public:
    int f(vector<vector<int>>& grid,int i,int j,int k,vector<vector<vector<int>>>&dp){
        if(i==grid.size()||j==grid[0].size()||k<0) return -1;
        if(i==grid.size()-1&&j==grid[0].size()-1){
            if(grid.back().back()!=0&&k==0) return -1;
            return grid.back().back();
        }
        if(dp[i][j][k]!=-2) return dp[i][j][k];
        if(grid[i][j]!=0) k--;
        int right=f(grid,i,j+1,k,dp); int down=f(grid,i+1,j,k,dp);
        if(grid[i][j]!=0) k++;
        return dp[i][j][k]=max(right,down)==-1?-1:grid[i][j]+max(right,down);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(min(k+1,m+n),-2)));
        return f(grid,0,0,min(k,m+n-1),dp);
    }
};
