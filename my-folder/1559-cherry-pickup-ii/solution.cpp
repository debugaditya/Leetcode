class Solution {
public:
    vector<vector<int>>dir={{-1,-1},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};
    int f(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        if(i==grid.size()||j1==grid[0].size()||j2==grid[0].size()||j1==-1||j2==-1) return 0;
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int curr=j1==j2?grid[i][j1]:grid[i][j1]+grid[i][j2],ans=0;
        for(auto it:dir){ans=max(ans,curr+f(i+1,j1+it[0],j2+it[1],grid,dp));}
        return dp[i][j1][j2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return f(0,0,grid[0].size()-1,grid,dp);
    }
};
