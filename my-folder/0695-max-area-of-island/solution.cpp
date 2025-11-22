class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        if(i<0||j<0||i==vis.size()||j==vis[0].size()||grid[i][j]==0||vis[i][j]) return 0;
        vis[i][j]=true;
        return 1+dfs(i+1,j,grid,vis)+dfs(i-1,j,grid,vis)+dfs(i,j+1,grid,vis)+dfs(i,j-1,grid,vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false)); int ans=0;
        for(int i=0;i<grid.size();i++) for(int j=0;j<grid[0].size();j++) if(!vis[i][j]) ans=max(dfs(i,j,grid,vis),ans);
        return ans;
    }
};
