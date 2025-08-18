class Solution {
public:
    bool f(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>&vis){
        if(i==grid.size()-1&&j==grid[0].size()-1) return true;
        if(vis[i][j]) return false;
        vis[i][j]=true;
        bool ans=false;
        if(grid[i][j]==1){
            if(j+1<grid[0].size()&&(grid[i][j+1]==1||grid[i][j+1]==3||grid[i][j+1]==5)) ans|=f(grid,i,j+1,vis);
            if(ans) return true;
            if(j-1>=0&&(grid[i][j-1]==1||grid[i][j-1]==4||grid[i][j-1]==6)) ans|=f(grid,i,j-1,vis);
            if(ans) return true;
        }
        if(grid[i][j]==2){
            if(i+1<grid.size()&&(grid[i+1][j]==2||grid[i+1][j]==5||grid[i+1][j]==6)) ans|=f(grid,i+1,j,vis);
            if(ans) return true;
            if(i-1>=0&&(grid[i-1][j]==2||grid[i-1][j]==3||grid[i-1][j]==4)) ans|=f(grid,i-1,j,vis);
            if(ans) return true;
        }
        if(grid[i][j]==3){
            if(i+1<grid.size()&&(grid[i+1][j]==2||grid[i+1][j]==6||grid[i+1][j]==5)) ans|=f(grid,i+1,j,vis);
            if(ans) return true;
            if(j-1>=0&&(grid[i][j-1]==1||grid[i][j-1]==4||grid[i][j-1]==6)) ans|=f(grid,i,j-1,vis);
            if(ans) return true;
        }
        if(grid[i][j]==4){
            if(j+1<grid[0].size()&&(grid[i][j+1]==1||grid[i][j+1]==3||grid[i][j+1]==5)) ans|=f(grid,i,j+1,vis);
            if(ans) return true;
            if(i+1<grid.size()&&(grid[i+1][j]==2||grid[i+1][j]==6||grid[i+1][j]==5)) ans|=f(grid,i+1,j,vis);
            if(ans) return true;
        }
        if(grid[i][j]==5){
            if(i-1>=0&&(grid[i-1][j]==2||grid[i-1][j]==4||grid[i-1][j]==3)) ans|=f(grid,i-1,j,vis);
            if(ans) return true;
            if(j-1>=0&&(grid[i][j-1]==1||grid[i][j-1]==4||grid[i][j-1]==6)) ans|=f(grid,i,j-1,vis);
            if(ans) return true;
        }
        if(grid[i][j]==6){
            if(j+1<grid[0].size()&&(grid[i][j+1]==1||grid[i][j+1]==3||grid[i][j+1]==5)) ans|=f(grid,i,j+1,vis);
            if(ans) return true;
            if(i-1>=0&&(grid[i-1][j]==2||grid[i-1][j]==4||grid[i-1][j]==3)) ans|=f(grid,i-1,j,vis);
            if(ans) return true;
        }
        return ans;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        return f(grid,0,0,vis);
    }
};
