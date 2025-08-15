class Solution {
public:
    long long dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        if(grid[i][j]==0) return 0;
        vis[i][j]=true;
        long long sum=grid[i][j];
        if(i+1<vis.size()&&!vis[i+1][j]) sum+=dfs(i+1,j,grid,vis);
        if(j+1<vis[0].size()&&!vis[i][j+1]) sum+=dfs(i,j+1,grid,vis);
        if(i-1>-1&&!vis[i-1][j]) sum+=dfs(i-1,j,grid,vis);
        if(j-1>-1&&!vis[i][j-1]) sum+=dfs(i,j-1,grid,vis);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt=0; vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j]&&grid[i][j]!=0) if(dfs(i,j,grid,vis)%k==0) cnt++;
            }
        }
        return cnt;
    }
};
