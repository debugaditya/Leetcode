class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&vis){
        if(i<0||j<0||i==vis.size()||j==vis[0].size()||grid[i][j]=='0'||vis[i][j]) return;
        vis[i][j]=true; dfs(i+1,j,grid,vis); dfs(i-1,j,grid,vis); dfs(i,j+1,grid,vis); dfs(i,j-1,grid,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false)); int ans=0;
        for(int i=0;i<grid.size();i++) for(int j=0;j<grid[0].size();j++) if(!vis[i][j]&&grid[i][j]=='1') {ans++; dfs(i,j,grid,vis);}
        return ans;
    }
};
