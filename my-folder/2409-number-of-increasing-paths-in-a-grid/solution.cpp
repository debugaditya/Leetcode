class Solution {
public:
    const int MOD=1000000007;
    int f(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        if(i==grid.size()||j==grid[0].size()||i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=0,down=0,right=0,left=0;
        if(j-1>=0&&grid[i][j-1]>grid[i][j]) left=f(grid,i,j-1,dp);
        if(i-1>=0&&grid[i-1][j]>grid[i][j]) up=f(grid,i-1,j,dp);
        if(j+1<grid[0].size()&&grid[i][j+1]>grid[i][j]) right=f(grid,i,j+1,dp);
        if(i+1<grid.size()&&grid[i+1][j]>grid[i][j]) down=f(grid,i+1,j,dp);
        return dp[i][j]=(1+left+right+up+down)%MOD;
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans=(ans+f(grid,i,j,dp))%MOD;
            }
        }
        return ans;
    }
};

